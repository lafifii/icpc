struct BipartiteMatcher{
	vector<vector<int>> G;
	vector<int> L, R; vector<bool> vis;
	BipartiteMatcher(int n, int m): G(n), L(n, -1), R(m, -1), vis(n) {}
	void add_edge(int a, int b){G[a].push_back(b);}
	bool Match(int node){
		if (vis[node]) return false;
		vis[node] = true;
		for(int&v: G[node]) if (R[v] == -1) return L[R[v] = node] = v, 1;
		for(int&v: G[node]) if (Match(R[v])) return L[R[v] = node] = v, 1;
		return 0;
	}
	int solve(){
		int cnt = 1, ret = 0;
		while(cnt--){
			fill(vis.begin(), vis.end(), 0);
			for(int i = 0; i<L.size(); i++) if (L[i] == -1) cnt |= Match(i);
		}
		for(int i = 0; i<L.size(); i++) ret+= (L[i] != -1);
		return ret;
	}
};
