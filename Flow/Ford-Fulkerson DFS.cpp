
int cap[maxn][maxn];
vector<int> vs[maxn];
 
int sink;
int dfs(int v, int f){
	vis[v] = true;
	if (v == sink) return f;
	for(int e: vs[v]) if (!vis[e] && cap[v][e] > 0){
		int flow = dfs(e, min(f, cap[v][e]));
		if (flow > 0){
			cap[v][e] -= flow;
			cap[e][v] += flow;
			return flow;
		}
	}
	return 0;
}
 
int maxflow(int s, int t){
	int flow = 0, new_flow = 0;
	sink = t;
	while(new_flow = dfs(s, maxn)){
		flow += new_flow;
		memset(vis, 0, sizeof(vis));
	}
	return flow;
}
