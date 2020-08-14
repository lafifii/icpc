/* TIME COMPLEXITIES
Regular: O(E*V^2), usually faster in practice
Bipartite Matching: O(sqrt(V)*E)
Unit Capacity Network: O(min(V^(2/3), E^(1/2))*E)
*/
/* TIME COMPLEXITIES
Regular: O(E*V^2), usually faster in practice
Bipartite Matching: O(sqrt(V)*E)
Unit Capacity Network: O(min(V^(2/3), E^(1/2))*E)
*/
struct Dinic{
	int nodes, src, dst;
	vector<int> dist, q, work;
	struct edge{int to, rev, f, cap;};
	vector<vector<edge>> g;
	Dinic(int x): nodes(x),g(x),dist(x), q(x), work(x){}
	void add_edge(int s, int t, int cap){
		g[s].push_back((edge){t, int(g[t].size()), 0, cap});
		g[t].push_back((edge){s, int(g[s].size())-1, 0, 0});
	}
	bool dinic_bfs(){
		fill(dist.begin(), dist.end(), -1); dist[src] = 0;
		int qt = 0; q[qt++] = src;
		for (int qh = 0; qh<qt; qh++){
			int u = q[qh];
			for(int i = 0; i<g[u].size(); i++){
				edge &e = g[u][i]; int v = g[u][i].to;
				if (dist[v]<0 and e.f<e.cap) dist[v] = dist[u]+1, q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	int dinic_dfs(int u, int f){
		if (u == dst) return f;
		for(int &i = work[u]; i<g[u].size(); i++){
			edge &e = g[u][i];
			if (e.cap <=e.f) continue;
			int v = e.to;
			if (dist[v] == dist[u]+1){
				int df = dinic_dfs(v, min(f, e.cap-e.f));
				if (df>0){e.f+=df; g[v][e.rev].f-=df; return df;}
			}
		}
		return 0;
	}
	int max_flow(int _src, int _dst){
		src = _src; dst = _dst;
		int result = 0;
		while(dinic_bfs()){
			fill(work.begin(), work.end(), 0);
			while(int delta = dinic_dfs(src, 1e9)) result+=delta;
		}
		return result;
	}
};


