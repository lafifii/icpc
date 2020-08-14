//define 'maxn' and 'inf' as type const int
int n, m;
int c[maxn];
int pnode[maxn];
int pedge[maxn];
struct edge{
	int to, cap, flow, rev;
	edge(){};
	edge(int to_, int cap_, int flow_, int rev_) :
		to(to_), cap(cap_), flow(flow_), rev(rev_) {}
};
vector<edge> G[maxn];
void addEdge(int u, int v, int cap){
	int idu = G[u].size();
	int idv = G[v].size();
	G[u].emplace_back(edge(v,cap,0,idv));
	G[v].emplace_back(edge(u,0,0,idu));
}
int BFS(int s, int t){
	memset(pnode, -1, sizeof pnode);
	pnode[s] = -2;
	queue< pair<int,int> > Q;
	Q.push({s, inf});
	while(Q.size()){
		int u = Q.front().first;
		int flow = Q.front().second;
		Q.pop();
		for(int i=0; i<G[u].size(); i++){
			edge e = G[u][i];
			if(pnode[e.to] != -1) continue;
			if(e.cap - e.flow > 0){
				pnode[e.to] = u;
				pedge[e.to] = i;
				int new_flow = min(flow, e.cap - e.flow);
				if(e.to == t) return new_flow;
				else Q.push({e.to, new_flow});
			}
		}
	}
	return 0;
} 
int maxflow(int s, int t){
	int flow = 0;
	int new_flow;
	while(new_flow = BFS(s,t)){
		flow += new_flow;
		int v = t;
		while(v != s){
			int u = pnode[v];
			int e = pedge[v];
			G[u][e].flow += new_flow;
			G[v][G[u][e].rev].flow -= new_flow;
			v = u;
		}
	}
	return flow;
}
