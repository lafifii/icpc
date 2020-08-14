#include <bits/stdc++.h>
using namespace std;
const int N = 500;
vector<int> lad[N];
int entry[N], low[N];
bool vis[N];
// O (n + m)
void dfs(int u, int &t, int p = -1){
	vis[u] = 1, entry[u] = low[u] = t++;
	for(int v : lad[u]){
		if(u == v) continue;
		if(vis[v]) low[u] = min(low[u], entry[v]);
		else{
			dfs(v, t, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > entry[u]){
				//bridge
			}
		}
	}
}
void findBridges(int n){
	int t = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; ++i){
		if(!vis[i])
			dfs(i, t);
	}
}
int main() {
	
	return 0;
}
