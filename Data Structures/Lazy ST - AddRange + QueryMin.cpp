#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
struct SegTree{
	int n;
	vector<long long> st;
	vector<long long> lazy;
	SegTree() {} 
	SegTree(int n) :
		n(n), st(4 * n, 0), lazy(4 * n, 0LL) {}
 
	void push(int pos, int l, int r){
		if(lazy[pos]){
			st[pos] += lazy[pos];
			if(l < r){
				lazy[2*pos] += lazy[pos];
				lazy[2*pos+1] += lazy[pos];
			}
			lazy[pos] = 0;
		}
	}
 
	void update(int x, int y, long long z, int pos, int l, int r){
		push(pos,l,r);
		if(y < l or r < x or x > y) return;
		if(x <= l and r <= y){
			lazy[pos] += z;
			push(pos,l,r);
			return;
		}
		int mi = (l+r) / 2;
		update(x,y,z,2*pos,l,mi);
		update(x,y,z,2*pos+1,mi+1,r);
		st[pos] = min(st[2*pos], st[2*pos+1]);
	}
 
	void update(int x, int y, long long z){
		update(x, y, z, 1, 0, n-1);
	}
 
	long long query(int x, int y, int pos, int l, int r){
		push(pos,l,r);
		if(y < l or r < x or x > y) return inf;
		if(x <= l and r <= y) return st[pos];
		int mi = (l+r) / 2;
		return min(query(x,y,2*pos,l,mi), query(x,y,2*pos+1,mi+1,r));
	}
 
	long long query(int x, int y){
		return query(x, y, 1, 0, n-1);
	}
};
