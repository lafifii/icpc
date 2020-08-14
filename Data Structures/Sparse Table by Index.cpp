int st[stK][maxn]; //stK such that 2^stK >= maxn
void build(int n, int*a){
	for(int i = 0; i<n; i++) st[0][i] = i;
	for(int k = 1; k<stK; k++){
		for(int i = 0; i<n-(1<<k)+1; i++){
			if (a[st[k-1][i]] < a[st[k-1][i+(1<<(k-1))]]) st[k][i] = st[k-1][i];
			else st[k][i] = st[k-1][i+(1<<(k-1))];
		}
	}
}
 
int query(int l, int r, int*a){ // [L, R), call with R+1
	int k = 31-__builtin_clz(r-l);
	if (a[st[k][l]]<=a[st[k][r-(1<<k)]]) return st[k][l];
	return st[k][r-(1<<k)];
}
