int ST[maxn][40];
void build(int n, vector<int>&a){ 
	for(int i = 0; i < n; i++) ST[i][0] = a[i];
	for(int j = 1; (1 << j) <= n; ++j) 
		for(int i = 0; i + ( 1<< j) <= n; ++i)
		ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1) ) ][j - 1]);
}
int query(int L, int R){ //[L, R]
	int ans = INT_MAX, T =  R - L + 1;
	int lg = 31 - (__builtin_clz(T));
	for(int j = lg; j >= 0; --j){
		if( (1<<j) <= T){
			ans = min(ans, ST[L][j]);
			L+= ( 1 << j );
			T-= ( 1 << j );
		}
	}
	return ans;
}
