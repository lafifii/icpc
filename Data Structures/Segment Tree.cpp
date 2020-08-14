const int maxn = 1e5;

int t[maxn], a[maxn];
int NE = 0;
int merge(int a, int b){
	return a + b;	
}

void build(int v, int l, int r){
	if(l == r) t[v] = a[l];
	else{
		int mid = (l + r)/2;
		build(2*v, l, mid);
		build(2*v + 1, mid + 1, r);
		t[v] = merge(t[2*v], t[2*v + 1]);
	}
}

int query(int v, int l, int r, int lo, int hi){
	if(lo > hi) return NE;	
	if(l == lo and r == hi) return t[v];
	int mid = (l + r)/2;
	return merge(query(2*v, l, mid, lo, min(mid, hi)) , query(2*v + 1, mid + 1, r, max(mid + 1, lo), hi));
}

int update(int v, int l, int r, int pos, int val){
	if(l == r) t[v] = a[pos] = val;
	else{
		int mid = (l + r)/2;
		if(pos <= mid) update(2*v, l, mid, pos, val);
		else update(2*v + 1, mid + 1, r, pos, val);
		t[v] = merge(t[2*v], t[2*v + 1]);
	}
}