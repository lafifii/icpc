#include <bits/stdc++.h>
using namespace std;
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
long long binpow(int a, int n, int mod){
  if(not n) return 1;
  long long res = binpow(a, n/2, mod);
  if(n%2) return res*res*a%mod;
  return res*res%mod;
}
// calculate a^(b^c) % mod
int cal(int a, int b, int c, int mod){
	int p = phi(mod);
	int ex = binpow(b,c,p);
	if(__gcd(a, mod) == 1) return binpow(a,ex,mod);
	else if(c >= log(log2(mod))/log(b) ) return binpow(a,ex + p,mod);
	return binpow(a, binpow(b,c, INT_MAX) , mod);
}
/* 
   if gcd(x,mod) == 1 -> x ^ (exp mod phi(mod) ) % mod
   else if(exp >= log2(mpd) ) -> x ^ (phi(mod) + exp mod phi(mod)) % mod
   else x ^ exp % mod
*/
