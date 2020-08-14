const int maxn = 100;
int ST[11][maxn][11][maxn], a[maxn][maxn];
int logs[maxn];

void build(int n, int m){
	logs[0] = 1;
	for(int i = 2; i < maxn; ++i) logs[i] = logs[i/2] + 1;
	
	for (int ir = 0; ir < n; ir++) {
		for(int ic=0;ic<m;ic++)
	    	ST[ 0 ][ ir ][ 0 ][ ic ] = a[ir][ic];
	      
	  	for(int jc=1;jc<=10;jc++) {
	  		for(int ic=0; ic+(1<<(jc)) <= m; ic++) {
	     			ST[0 ][ir ][jc ][ic ] = max(ST[0 ][ir ][jc-1 ][ic ],ST[0 ][ir ][ jc-1 ][ ic+ (1<<(jc-1)) ]);
	    		}
		}
	}       

	for (int jr = 1; jr <= 10; jr++) {
		for (int ir = 0; ir+(1<<(jr)) <= n; ir++) {
			for (int jc = 0; jc <= 10; jc++) {
				for (int ic = 0; ic < m; ic++) {
					ST[jr][ir][jc][ic] = max(ST[jr-1][ir][jc][ic],ST[jr-1][ir+(1<<(jr-1)) ][jc ][ic ])  ;
				}
			}
		}
	}
}
int query(int x1, int y1, int x2, int y2) { // inclusivo
	
    int lenx=x2-x1+1;
    int kx = logs[lenx];
	
    int leny=y2-y1+1;
    int ky = logs[leny];

    int max_R1 = max ( ST[kx ][x1 ][ky ][y1 ] , ST[kx ][x1 ][ky ][ y2+1- (1<<ky) ] );
    int max_R2 = max ( ST[kx ][x2+1-(1<<kx) ][ky ][y1 ], ST[kx ][x2+1- (1<<kx) ][ky ][y2+1- (1<<ky) ] );
    return max ( max_R1, max_R2 );
}
