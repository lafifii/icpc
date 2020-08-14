const int maxn = 1e7 + 5;
int BIT[maxn], int n;
void update(int x, int val)
{
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
// 1 indexed
