long long gcd(long long a, long long b, long long &x, long long &y){
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long modinv(long long a, long long mod){
	long long x, y;
	gcd(a,mod,x,y);
	return (x%mod + mod)%mod;
} // O(log min(a,mod))

