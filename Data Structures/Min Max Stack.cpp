stack< pair<int,int> > s1, s2;
int merge(int a, int b){ return min(a, b); }
void pop(){
    if(s2.empty()){
        while(s1.size() > 0){
            int el = s1.top().first;
            int mn = s2.size() > 0 ? merge(s2.top().second, el) : el;
            s1.pop();
            s2.push({el, mn});
        }
    }
    if(s2.size() > 0) s2.pop();
}
int front(){
    if(s2.empty()){
        while(s1.size() > 0){
            int el = s1.top().first;
            int mn = s2.size() > 0 ? merge(s2.top().second, el) : el;
            s1.pop();
            s2.push({el, mn});
        }
    }
    return s2.top().first;
}
void push(int x){
    int mn = s1.size() > 0 ? merge(s1.top().second, x) : x;
    s1.push({x, mn});
}
