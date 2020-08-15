const int maxn = 2e5 + 20;
long long t[4*maxn], lazy[4*maxn];
int a[maxn];

long long merge(long long a, long long b){
	return min(a, b);
}
void push(int v){
	t[2*v]+= lazy[v];
	lazy[2*v]+= lazy[v];
	t[2*v + 1]+= lazy[v];
	lazy[2*v + 1]+= lazy[v];
	lazy[v] = 0;
}
void build(int v, int l, int r){
	if(l == r) t[v] = a[l];
	else{
		int mid = (l + r)/2;
		build(2*v, l, mid);
		build(2*v + 1, mid + 1, r);
		t[v] = min(t[2*v], t[2*v+1]);
	}
}
void upd(int v, int l, int r, int lo, int hi, int val){
	if(lo > hi) return;
	if(lo == l and r == hi){
		t[v]+=val;
		lazy[v]+=val;
	}
	else{
		push(v);
		int mid = (l + r)/2;
		upd(2*v, l, mid, lo, min(mid, hi), val);
		upd(2*v+1, mid + 1, r, max(mid + 1, lo), hi, val);
		t[v] = merge(t[2*v], t[2*v+1]);
	}
}

long long query(int v, int l, int r, int lo, int hi){
	if(lo > hi) return LLONG_MAX;
	if(lo == l and r == hi) return t[v];
	push(v);
	int mid = (l + r)/2;
	long long a = query(2*v,l,mid,lo, min(mid, hi));
	long long b = query(2*v + 1,mid+1,r,max(lo,mid+1), hi);
	return merge(a, b);
}

