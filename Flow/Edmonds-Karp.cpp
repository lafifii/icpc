int p[maxn], cap[maxn][maxn];
vector<int> vs[maxn];

int bfs(int s, int t){
	memset(p, -1, sizeof(p));
	p[s] = -2;
	queue<pair<int,int>> q;
	q.emplace(make_pair(s, int(1e9)));
	while(q.size()){
		int v = q.front().first, f = q.front().second;
		q.pop();
		for(int e: vs[v]) if (p[e] == -1 && cap[v][e] > 0){
			p[e] = v;
			int nf = min(f, cap[v][e]);
			if (e == t) return nf;
			q.emplace(make_pair(e, nf));
		}
	}
	return 0;
}


int maxflow(int s, int t){
	int flow = 0, new_flow = 0;
	while(new_flow = bfs(s,t)){
		flow += new_flow;
		int v = t;
		while(v != s) {
			int u = p[v];
			cap[u][v] -= new_flow;
			cap[v][u] += new_flow;
			v = u;
		}
	}
	return flow;
}
