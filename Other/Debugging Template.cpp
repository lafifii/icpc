#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio() ios_base::sync_with_stdio(false);
#define rmod(x, y) ((((x)%(y))+(y))%(y))
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T, typename R = null_type, typename C = less<T>>
tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
	return tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>();
}
template<typename T> int __SIZE(T (&t)){ return t.size(); }
template<typename T, size_t N> int __SIZE(T (&t)[N]){ return N; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p);
template<typename T, typename... Coords>
string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C);
template<typename T, typename... Coords>
string to_string(const T (&t), int x1, int x2, Coords... C){
    string ret = "{"; x1 = min(x1,__SIZE(t)); auto e = begin(t); advance(e,x1);
    for(int i = x1, _i = min(x2,__SIZE(t)-1); i <= _i; ++i)
        ret += to_string(*e, C...) + (i != _i ? ", " : ""), e = next(e);
    return ret + "}";
}
template<typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << ' ' << to_string(H);
	debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define debugm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#else
#define debug(...) 42
#define debugm(...) 42
#endif
/*
1.debug(args): Acepta cualquier cantidad de argumentos de CUALQUIER tipo de dato, incluido pair y colecciones.
  Solo funciona para  colecciones iterables (vector, set, etc.). No acepta arreglos de C (int a[n]).
  
2.debugm(args): Solo acepta 1 arreglo/matriz de C como argumento, y límites [L, R) para cada dimension. Es medio feo
  e inconveniente para debugear arreglos pero no encontré nada mejor. Se vuelve medio ilegible para arreglos 
  multidimensionales asi que en general es mejor fijar la posición de todas las dimensiones y solo usar el debugm para
  imprimir la restante.
  Ejemplo: 
    int dp[3][2][3]; 
    debugm(dp); // Muestra todo
    debugm(dp, 0,3, 0,1, 0,3); // mostrará dp[i][0][j] para todo i,j en [0, 3)
    for(int i = 0; i<3; i++)
      for(int j = 0; j<2; j++){
        debugm(dp[i][j]);
      }
*/
int main(){
	
	return 0;
}
