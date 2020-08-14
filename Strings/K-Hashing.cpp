const int nhash = 2, maxn = 2e6 + 20;
typedef long long ll;

int p[nhash] = {31,101}, n;
int mod[nhash] = {1000000009, 1000000007};
ll p_pow[nhash][maxn], h[nhash][maxn];

void init(){
    memset(p_pow,0,sizeof(p_pow));
    for(int j = 0; j < nhash; ++j){
    	p_pow[j][0] = 1;
    	for(int i = 1; i < maxn; ++i)
    		p_pow[j][i] = (p_pow[j][i-1] * p[j]) % mod[j];
    }
}
int get(char c){
	return c - 'a' + 1;
}
void computeh(string &s){
    memset(h,0,sizeof(h));
    for(int j = 0; j < nhash; ++j){
    	for (int i = 0; i < n; i++){
        	h[j][i+1] = (h[j][i] + get(s[i])*p_pow[j][i])%mod[j];
    	}
    }
}
vector<ll> sub_h(int lo, int hi){
   vector<ll> ans(nhash, 0);
   for(int i = 0; i < nhash; ++i){
    	ans[i] = ((h[i][hi + 1] + mod[i] - h[i][lo]) + mod[i]) % mod[i];
    	ans[i] = (ans[i] * p_pow[i][n - lo - 1]) % mod[i];
    }
    return ans;
}
vector<ll> hash_s(string &s){
	vector<ll> ans(nhash, 0);
	for(int j = 0; j < nhash; ++j){
		for(int i = 0; i < s.size(); ++i)
			ans[j] = (ans[j] + (get(s[i])*p_pow[j][i])%mod[j])%mod[j];
	}
	return ans;
}
