struct LCA{
	vector<bool> vis; vector<int>* G;
	vector<int> tour, dep, first;
	vector<vector<int>> st; int stK; 
	LCA(int sz, vector<int>* vs): G(vs){
		stK = 32-__builtin_clz(2*sz);
		vis.resize(sz);	first.resize(sz, -1);
		preDFS(0, 0); build();
	}
	int query(int u, int v){ //returns LCA of U and V
		if (first[u] > first[v]) swap(v, u);
		return tour[stquery(first[u], first[v]+1)];
	} //Everything below is pre-processing
	void preDFS(int v, int d){
		vis[v] = true;
		if (first[v] == -1) first[v] = tour.size();
		tour.push_back(v); dep.push_back(d);
		for(auto&e: G[v]) if (not vis[e]){
			preDFS(e, d+1);
			tour.push_back(v); dep.push_back(d);
		}
	}
	void build(){ //SPARSE TABLE BY INDEX
		int n = dep.size(), idx;
		st.resize(stK, vector<int>(n));
		for(int i = 0; i<n; i++) st[0][i] = i;
		for(int k = 1; k<stK; k++){
			for(int i = 0; i<n-(1<<k)+1; i++){
				idx = i+(1<<(k-1));
				if (dep[st[k-1][i]] < dep[st[k-1][idx]]) st[k][i] = st[k-1][i];
				else st[k][i] = st[k-1][idx];
			}
		}
	}
	int stquery(int l, int r){
		int k = 31-__builtin_clz(r-l);
		if (dep[st[k][l]]<=dep[st[k][r-(1<<k)]]) return st[k][l];
		return st[k][r-(1<<k)];
	}
};
