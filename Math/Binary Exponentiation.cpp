const int mod = 1e9 + 7;
ll leading(ll a, ll b, ll n){ // a^b (first n digits)
    double x, y;
    x = b*log10(a); 
    y = floor(pow(10, x - floor(x) + n - 1));
    return y;
}
long long binpow(int a, int n){
  if(not n) return 1;
  long long res = binpow(a, n/2);
  if(n%2) return res*res*a%mod;
  return res*res%mod;
}
