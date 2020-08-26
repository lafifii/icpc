int qsz;
struct query{ int l, r, id;};
bool cmp(const query &a, const query &b){
    if(a.l/qsz != b.l/qsz) return a.l < b.l;
    return (a.l/qsz &1 ) ? a.r < b.r : a.r > b.r;
}
void mo(vector<query> qs){
    qsz = sqrt(n) + 1;
    sort(qs.begin(), qs.end(), cmp);
    vector<int> ans(qs.size(), 0);
    int lo = 0, hi = -1;
    for(query qq : qs){
        while (lo > qq.l) {
            lo--;
            add(lo);
        }
        while (hi < qq.r) {
            hi++;
            add(hi);
        }
        while (lo < qq.l) {
            rem(lo);
            lo++;
        }
        while (hi > qq.r) {
            rem(hi);
            hi--;
        }
        ans[qq.id] = get_answer();
    }
    for(int x: ans) printf("%d\n", x);
}
