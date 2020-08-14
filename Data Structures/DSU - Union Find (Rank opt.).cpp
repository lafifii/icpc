struct dset {
	int sz;
	vector<int> parent, rank;
	int &operator[](int pos){return parent[pos];}
	dset(int n): sz(n){
		parent.resize(n); rank.resize(n);
		for(int i = 0; i < sz; i++) make(i);
	}
	int size(){return sz;}	
	inline void make(int v) {parent[v] = v; rank[v] = 0;}
	void show(){for(int i = 0; i< sz; i++) printf("%d ", find(i));}
	bool join(int a, int b) {
	    a = find(a); b = find(b);
	    if (a != b) {
	        if (rank[a] < rank[b]) swap(a, b);
	        parent[b] = a;
	        if (rank[a] == rank[b]) rank[a]++;
	        return true;
    	}
    	return false;
	}
	int find(int v) {
	    if (v == parent[v]) return v;
	    return parent[v] = find(parent[v]);
	}
};
