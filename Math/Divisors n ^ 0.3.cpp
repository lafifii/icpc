#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
bitset<maxn> pr;
vector<long long> p;
int n;
void sieve(){
	pr.set();
	pr[0] = pr[1] = 0;
	for(long long i = 2; i*i < maxn; ++i){
		if(pr[i])
			for(long long j = i*i; j <= maxn; j+=i) 
				pr[j] = 0;
	}
	for(int i = 0; i < maxn; ++i) if(pr[i]) p.push_back(i);
}
bool esprimo(long long n){
	for(long long i = 0; i < p.size() and p[i] * p[i] <= n; ++i){
		while(n > 0 and n%p[i] == 0) return false;
	}
	return true;
}
int countDiv(long long n) // O(n^(1/3))
{ 
    if (n == 1) return 1; 
    long long ans = 1; 
    for (long long i = 0; i < p.size() and p[i]*p[i]*p[i] <= n ; ++i) {
        long long cnt = 1;  
        while (n > 0 and n % p[i] == 0)  
        { 
            n = n / p[i]; 
            cnt++;  
        } 
        ans = ans * cnt; 
    } 
  
    long long raiz = sqrt(n);
    if (n < maxn and pr[n]) ans*=2;
    else if(n >= maxn and esprimo(n)) ans*=2;
    else if(raiz*raiz == n and raiz < maxn and pr[raiz]) ans*=3;
    else if(raiz >= n and esprimo(raiz)) ans*=3;
    else if (n != 1) ans = ans * 4; 
    return ans; 
} 
int main() {
	sieve();
	long long n;
	cin >> n;
	cout << countDiv(n);
	return 0;
}
