const int mod = 1e9+7;
inline int add(int a, int b, int m = mod ) { return (a+b) % m; };
inline int mul(ll a, ll b, int m = mod) { return (a*b) % m; };

int matsz;
struct mat{
	int a[maxn][maxn];
	mat operator * (const mat &o) const {
		assert(matsz>0); 
		mat r = {};
		for(int i = 0; i<matsz; i++)
			for(int j = 0; j<matsz; j++)
				for(int k = 0; k<matsz; k++)
					r.a[i][j] = add(r.a[i][j], mul(a[i][k], o.a[k][j]));
		return r;
	}
} base, ans;

//fastpow example
while(b>0){
	if (b&1) ans = ans * base;
	base = base * base;
	b >>= 1;
}
