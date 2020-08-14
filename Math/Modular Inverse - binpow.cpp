long long phi(long long n){
	long long result = n;
	for(int i = 2; i*i <= n; ++i){
		if(n%i) continue;
		while(n%i == 0) n/=i;
		result-= result/i;
	} 
	if(n > 1) result-=result/n;
	return result;
}
long long binpow(long long a, long long n, long long mod){
	if(not n) return 1;
	long long res = binpow(a, n/2, mod);
	if(n%2) return res*res*a%mod;
	return res*res%mod;
}
// a^(phi(m)- 1) = a^-1 mod m
long long modinv(long long a, long long mod){
	long long n = phi(mod) - 1;
	if(__gcd(a, mod) == 1) return binpow(a, n, mod);
	return -1; // No solution
} // O(log m + log(min(a,m)))

