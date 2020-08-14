const int maxn = 1e3 + 40;
int bit[maxn][maxn], n, m, a[maxn][maxn];

void update(int y, int x, int val){
	for( ; y <= n; y+= y&-y)
		for(int j = x; j <= m; j+= j&-j)
			bit[y][j]+= val;
		
}
int query(int y, int x){
	int sum = 0;
	for(; y > 0; y-= y&-y)
		for(int j = x; j > 0; j-= j&-j) sum+= bit[y][j];
	
	return sum;
}
int query_sq(int x1, int y1, int x2, int y2){
	int v1 = query(y2, x1 - 1);
	int v2 = query(y1 - 1, x2);
	int v3 = query(y1 - 1, x1 - 1);
	return query(y2, x2) - v1 - v2 + v3;
}
