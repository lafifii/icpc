const int maxn = 1e3 + 10;

int n,m, tipo = 0;
long long mt[maxn][maxn],st[2*maxn][2*maxn];

void build(){
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) st[i+n][j+m] = mt[i][j];
	
	for(int i = 0; i < n; ++i) 
		for(int j=m-1;j;--j)
			st[i+n][j] = min(st[i+n][j<<1],st[i+n][j<<1|1]);
	
	for(int i=n-1;i;--i)
		for(int j = 0; j < 2*m; ++j)
			st[i][j]= min(st[i<<1][j],st[i<<1|1][j]);
}
void upd(int x, int y, int v){
	st[x+n][y+m]=v;
	
	for(int j=y+m;j>1;j>>=1) st[x+n][j>>1] = min(st[x+n][j],st[x+n][j^1]);
	
	for(int i=x+n;i>1;i>>=1)
		for(int j=y+m;j;j>>=1)
			st[i>>1][j]= min(st[i][j],st[i^1][j]);
}
long long query(int x0, int y0, int x1, int y1){ // abierto no incluye x1 y1
	long long r = LLONG_MAX; // elemento neutro
	for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
		int t[4],q=0;
		if(i0&1)t[q++]=i0++;
		if(i1&1)t[q++]=--i1;
		for(int k = 0; k < q; ++k){
			for(int j0 = y0+m, j1=y1+m; j0<j1; j0>>=1, j1>>=1){
				if(j0&1) r = min(r,st[t[k]][j0++]);
				if(j1&1) r = min(r,st[t[k]][--j1]);
			}
		}
	}
	return r;
}
