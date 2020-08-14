#include<bits/stdc++.h>
using namespace::std;

const long long INF = 1LL<<62;

struct MCMF{
	struct edge{
		int to;
		long long cap;
		long long flow;
		long long cost;
		edge(){}
		edge(int to_, long long cap_, long long flow_, long long cost_) : 
			to(to_), cap(cap_), flow(flow_), cost(cost_) {}
	};

	int n;
	int s;
	int t;
	vector<edge> E;
	vector<int> pnode;
	vector<int> pedge;
	vector<long long> d;
	vector<vector<int>> G;

	typedef pair<long long,int> lli;

	MCMF(){};

	MCMF(int n_, int s_, int t_) :
		n(n_), s(s_), t(t_), G(n, vector<int>()), pnode(n), pedge(n), d(n){}

	void addEdge(int a, int b, long long cap, long long cost){
		int index = E.size();
		E.emplace_back(edge(b,cap,0,cost));
		E.emplace_back(edge(a,0,0,-cost));
		G[a].emplace_back(index);
		G[b].emplace_back(index+1);
	}

	long long augment(int v, long long flow = INF){
		if(v == s) return flow;
		else if(pnode[v] != -1){
			int e = pedge[v];
			long long act_flow = augment(pnode[v], min(flow, E[e].cap - E[e].flow));
			E[e].flow += act_flow;
			E[e^1].flow -= act_flow;
			return act_flow;
		}
		return 0LL;
	}
	
	void Dijkstra(){
		pnode.assign(n,-1);
		d.assign(n,INF);
		pnode[s] = -2;
		d[s] = 0LL;
		priority_queue<lli, vector<lli>, greater<lli>> Q;
		Q.emplace(make_pair(0LL, s));
		while(!Q.empty()){
			int u = Q.top().second;
			long long w = Q.top().first;
			Q.pop();
			if(d[u] < w) continue;
			for(int i=0; i<G[u].size(); i++){
				edge e = E[G[u][i]];
				if(e.cap - e.flow == 0) continue;
				if(d[e.to] > d[u] + e.cost){
					d[e.to] = d[u] + e.cost;
					pnode[e.to] = u;
					pedge[e.to] = G[u][i];
					Q.emplace(make_pair(d[e.to],e.to));
				}
			}
		}
	}

	long long mcmf(){
		long long ans = 0LL;
		while(true){
			Dijkstra();
			long long new_flow = augment(t);
			if(new_flow == 0) break;
			ans += new_flow * d[t];
		}
		return ans;
	} //returns cost
};

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	MCMF M(n,0,n-1);
	int a, b, cap, cost;
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d",&a,&b,&cap,&cost);
		a--; b--;
		M.addEdge(a,b,cap,cost);
	}
	cout << M.mcmf() << endl;
	return 0;
}

/*
Input for testing:
4 5
1 2 1 2
1 3 2 2
3 2 1 1
2 4 2 1
3 4 2 3

Should output 12
*/

