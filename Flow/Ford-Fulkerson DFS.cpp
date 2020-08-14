//Time complexity O(E*|F|)
int send(int v, int curm){
	vis[v] = true;
	if (v == SINK) return curm;
	int cap;
	for(int i = 1; i<maxn; i++){
		if (i == v) continue;
		cap = G[v][i]-F[v][i];
		if (vis[i] == false and cap>0){
			int sent = send(i, min(curm, cap));
			if (sent>0){
				F[v][i]+=sent;
				F[i][v]-=sent;
				return sent;
			}
		}
	}
	return 0;
}
//Call in main
while(int sent = send(SOURCE,INF)){
	total+= sent;
	memset(vis, 0, sizeof(vis));
}
