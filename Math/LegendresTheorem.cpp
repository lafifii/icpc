// veces de P en N! log(n)
int veces(long long n , int p){
	int cnt = 0;
	for(int k = p; k <= n; k*= p)
		cnt+= (n/k);
	
	return cnt;
}
