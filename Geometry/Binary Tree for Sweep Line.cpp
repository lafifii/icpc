struct Node{
	int seg;
	struct Node *down;
	struct Node *up;
};

Node *root;
int nodes_last;
Node nodes[maxn];
int empty_nodes_last;
Node *empty_nodes[maxn]; 
 
void init_bin_tree() {
	root = NULL;
	nodes_last = -1;
	empty_nodes_last = -1;
}
 
Node* new_node(int seg) {
	Node * node;
 
	if( empty_nodes_last < 0) {
		node = &nodes[++nodes_last];
		assert(nodes_last < maxn);
	} else {
		node = empty_nodes[empty_nodes_last--];
	}
	node->seg = seg;
	node->up = NULL;
	node->down = NULL;
	return node;
}
 
Node* inserNode(Node *node, int seg, int x){
	if(node == NULL)
		return new_node(seg);
	else {
		if( segment_above( seg, node->seg, x)  ) {
			node->up = inserNode(node->up, seg, x);
		}
		else {
			node->down = inserNode(node->down, seg, x);
		}
		return node;
	}
}
 
Node* delete_node(Node* node, int seg, int x){
	Node* repl_node;
 
	if(node == NULL)
		return NULL;
	else {
	  if(node->seg == seg) {
		/* delete_node node */
		if(node->down == NULL) {
			empty_nodes[++empty_nodes_last] = node;
			return node->up;
		} else if(node->up == NULL) {
			empty_nodes[++empty_nodes_last] = node;
			return node->down;
		} else {
			repl_node = node->down;
			while( repl_node->up != NULL) repl_node = repl_node->up;				
			node->seg = repl_node->seg;
			node->down = delete_node(node->down, node->seg, x);
			return node;
		}
	  }
	  else {
		if( segment_above(seg, node->seg, x) ) {
			node->up = delete_node(node->up, seg, x);
		}
		else {
			node->down = delete_node(node->down, seg, x);
		}
		return node;
	  }  
	}
}
