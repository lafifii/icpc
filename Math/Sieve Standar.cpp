const int maxn = 1e5;
bitset<maxn> pr; 
int n;
void sieve(){
	pr.set();
	pr[0] = pr[1] = 0;
	for(int i = 2; i*i <= n; ++i){
		if(pr[i])
			for(int j = i*i; j <= n; j+=i) 
				pr[j] = 0;
	}
} // O(n log log sqrt(n) )
