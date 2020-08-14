//Only works on gcc/g++ compiler
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//<key, map_type, comparator>
template<typename T, typename R = null_type, typename C = less<T>>
using ordered_set = tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<pair<int,int>> example1; 	//use like set
ordered_set<int, int> example2; 	//use like map
//if you need multiset, store a timestamp along with elements (ie: pair<type, int>)

//order_of_key(T x): Returns number of stored items strictly smaller than X
//find_by_order(int K): Returns iterator to K-th largest element (counting from zero)
