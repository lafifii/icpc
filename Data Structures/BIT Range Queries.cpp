const int maxn = 2e5 + 60;
int bit[2][maxn], a[maxn], n;
void update(int id, int x, int val){
	for( ; x <= n; x+= x&-x) bit[id][x]+= val;
}
void update_range(int x, int y, int val){
	update(0, x, val);
	update(0, y + 1, -val);
	update(1, x, (x - 1)*val);
	update(1, y + 1, -y*val);
}
int query(int id, int x){
	int sum = 0;
	for(; x > 0; x-= x&-x) sum+= bit[id][x];
	return sum;
}
int query_range(int x){
	return query(0, x)*x - query(1, x);
}
