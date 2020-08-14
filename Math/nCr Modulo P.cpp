int f[MAXN]; //Pre-computed array of factorials modulo p
int inv(int n, int p) { return fpow(n, p-2, p); } 
int ncr(int n, int k, int p) { 
    if (k == 0 or n == k) return 1;
    int ans = f[n]*inv(f[k])%p * inv(f[n-k])%p;
    return ans%p;
} 