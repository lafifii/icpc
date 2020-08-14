const int p = 31;
const int mod = 1e9 + 9;
const int maxn = 1e7;
typedef long long ll;
ll p_pow[maxn], h[maxn];
void init(){
    memset(p_pow,0,sizeof(p_pow));
    p_pow[0] = 1;
    for (int i = 1; i < maxn; i++) p_pow[i] = (p_pow[i-1] * p) % mod;
}
void computeh(string &s){
    memset(h,0,sizeof(h));
    int n = s.size();
    for (int i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) *p_pow[i])%mod;
    }
}
ll sub_h(int lo, int hi, int n){
    ll ans = (h[hi + 1] + mod - h[lo]) % mod;
    ans = (ans * p_pow[n - lo - 1]) % mod;
    return ans;
}
