//Only works on GNU compiler (g++). 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename KEY, typename MAPT = null_type, typename COMPARATOR = less<KEY>>
tree<KEY, MAPT, COMPARATOR, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
	return tree<KEY, MAPT, COMPARATOR, rb_tree_tag, tree_order_statistics_node_update>();
} 

auto example1 = ordered_set<pair<int,int>>(); 	//use like set
auto example2 = ordered_set<int, int>(); 		    //use like map

//order_of_key(T x): Returns number of stored items strictly smaller than X
//find_by_order(int K): Returns iterator to K-th largest element (counting from zero)
