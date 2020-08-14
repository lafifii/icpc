const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];
int join(int a, int b){
  return max(a, b);
}
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = join(t[i<<1] , t[i<<1|1]);
}
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = join(t[p],t[p^1]);
}
int query(int l, int r) {  // join on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = join(res, t[l++]);
    if (r&1) res = join(res, t[--r]);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i); // add value on position N + i, 0 indexed
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}
