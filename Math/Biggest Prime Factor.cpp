int big[n + 1] = {1, 1};
void sieve_bpf(){
	for (int i = 1; i <= n; ++i)
		if (big[i] == 1)
	 		for (int j = i; j <= n; j += i)
	   			big[j] = i;
} // O(nloglogn)
vector<int> fact(int n) {
	vector<int> factors;
	while (n > 1) {
		factors.push_back(big[n]);
		n /= big[n];
	}
	return factors;
} // O(logn)