#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5, alp = 2; // suma de caracteres, alp
int t[maxn][alp], term[maxn], vis[maxn], nodos = 1, best[maxn];;
int getid(char c){
	return c - '0';
}
void add(string s){
	int act = 0;
	for(char c: s){
		int id = getid(c);
		if(t[act][id] == 0) t[act][id] = nodos++;
		vis[act]++;
		act = t[act][id];
	}
	term[act]++;
	vis[act]++;
}
pair<int,int> dfs(int u){ // closest terminal node that is the lexicographical smallest
	int dis = (term[u] ? 0 : INT_MAX), nodo = u;
	for(int i = 0; i < alp; ++i){
		if(t[u][i]){
			pair<int,int> dis_nodo = dfs(t[u][i]); 
			if(1 + dis_nodo.first < dis){
				dis = 1 + dis_nodo.first;
				nodo = dis_nodo.second;
			}
		}
	}
	best[u] = nodo; 
	return make_pair(dis, nodo);
}
bool search(string s){
	int act = 0;
	for(char c: s){
		int id = getid(c);
		if(t[act][id] == 0) return false;
		act = t[act][id];
	}
	return term[act]; // si es nodo terminal term[act] > 0
}
void remove_oc(string s){
	if(s.size() == 0) return;
	int act = 0, id, parent;
	vis[0]--;
	for(int i = 0; i < s.size(); ++i){
		id = getid(s[i]);
		parent = act;
		act = t[act][id];
		vis[act]--;
		if(!vis[act]) t[parent][id] = 0;
	}
	term[act]--;
}
void init(){
	memset(t,0,sizeof(t));
	memset(term,0,sizeof(term));
	memset(vis,0,sizeof(vis));
}
