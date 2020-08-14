struct dset {
	int sz;
	vector<int> parent, sze;
	int &operator[](int pos){return parent[pos];}
	dset():{};
	dset(int n): sz(n){
		parent.resize(n); sze.resize(n);
		for(int i = 0; i < sz; i++) make(i);
	}
	inline int size(){return sz;}
	inline int csize(int v){return sze[find(v)];}
	inline void make(int v) {parent[v] = v; sze[v] = 1;}
	void show(){for(int i = 0; i< sz; i++) printf("%d ", find(i));}
	bool join(int a, int b) {
	    a = find(a); b = find(b);
	    if (a != b) {
	        if (sze[a] < sze[b]) swap(a, b);
	        parent[b] = a;
	        sze[a] += sze[b];
	        return true;
    	    }
    	    return false;
	}
	int find(int v) {
	    if (v == parent[v]) return v;
	    return parent[v] = find(parent[v]);
	}
};
