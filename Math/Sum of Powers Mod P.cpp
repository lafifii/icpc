/*
  Sn = a^1 + a^2 ... + a^n = (p^(n + 1) - 1)/(p - 1) 
*/
ll binary_exponent(ll x, ll y, ll mod) {
  ll res = 1; 
  ll p = x; 
  while (y) {
    if (y % 2) { 
      res = (res * p) % mod; 
    }    
    p = (p * p) % mod; 
    y /= 2;
  }
  return res; 
}

ll gp_sum(ll a, int n, ll mod) {
  ll A = 1; 
  int num = 0; 
  ll res = 0; 
  ll degree = 1; 
  while (n) {
    if (n & (1 << num)) {
      n &= (~(1 << num));
      res = (res + (A * binary_exponent(a, n, mod)) % mod) % mod; 
    }    
    A = (A + (A * binary_exponent(a, degree, mod)) % mod) % mod; 
    degree *= 2;
    num++;
  }
  return res; 
}
