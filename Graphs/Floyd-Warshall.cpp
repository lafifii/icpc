void FloydWarshall(){
	//Initialize nxt[u][v] = v for all edges (u,v) in advance
	for(int i = 0; i<n; i++) d[i][i] = 0, nxt[i][i] = i;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			if (i!=j && d[i][j] != 1) d[i][j] = 1e9;
	for(int k = 0; k<n; k++)
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				if (d[i][j]>d[i][k]+d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}			
}

void reconstruct(int u, int v, vector<int> &path){
	if (nxt[u][v] == -1) return;
	path.push_back(u);
	while(u != v){
		u = nxt[u][v];
		path.push_back(u);
	}
}
