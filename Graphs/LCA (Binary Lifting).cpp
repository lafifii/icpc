bool vis[maxn];
int up[stK][maxn];
int n, dep[maxn];
vector<int> vs[maxn];

void dfs(int v){
	vis[v] = true;
	for(auto&e: vs[v]){
		if(not vis[e]){
			up[0][e] = v;
			dep[e] = dep[v]+1;
			dfs(e);
		}
	}
}
int goup(int v, int k){
	for(int d = 0; d<stK and v != -1; d++)
		if ((1<<d)&k) v = up[d][v];
	return v;
}
int query(int u, int v){
	if (dep[u]<dep[v]) swap(u, v);
	if (dep[u]>dep[v]) u = goup(u, dep[u]-dep[v]);
	if (u == v) return u;
	for(int k = stK-1; k>=0; k--)
		if (up[k][u] != up[k][v]) u = up[k][u], v = up[k][v];
	return up[0][u];
}
void buildLCA(){
	dfs(0); int aux;
	for(int k = 1; k<stK; k++){
		for(int i = 0; i<n; i++){
			aux = up[k-1][i];
			if (aux != -1) up[k][i] = up[k-1][aux];
		}
	}
}
