vector<int> suffix_array(string &s, int char_bound = -1) {
  int n = s.size();
  vector<int> a(n);
  if (n == 0) {
    return a;
  }
  if (char_bound != -1) {
    vector<int> aux(char_bound, 0);
    for (int i = 0; i < n; i++) {
      aux[s[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < char_bound; i++) {
      int add = aux[i];
      aux[i] = sum;
      sum += add;
    }
    for (int i = 0; i < n; i++) {
      a[aux[s[i]]++] = i;
    }
  } else {
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&](int i, int j) { return s[i] < s[j]; });
  }
  vector<int> sorted_by_second(n);
  vector<int> ptr_group(n);
  vector<int> new_group(n);
  vector<int> group(n);
  group[a[0]] = 0;
  for (int i = 1; i < n; i++) {
    group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
  }
  int step = 1;
  while (step < n) {
    int at = 0;
    int L = 0, R = 0;
    while(L < n){
      while(R < n and group[a[L]] == group[a[R]]) R += 1;
      for(int j=L; j<R; j++){
        if(a[j] - step >= 0){
          sorted_by_second[at++] = a[j] - step;
        }
      }
      for(int j=L; j<R; j++){
        if(a[j] - step < 0){
          sorted_by_second[at++] = a[j] - step + n >= 0? a[j] - step + n : a[j] - step + n + n;
        }
      }
      L = R;
    }
    for (int i = n - 1; i >= 0; i--) {
      ptr_group[group[a[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      int x = sorted_by_second[i];
      a[ptr_group[group[x]]++] = x;
    }
    new_group[a[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (group[a[i]] != group[a[i - 1]]) {
        new_group[a[i]] = new_group[a[i - 1]] + 1;
      } else {
        int pre = (a[i - 1] + step >= n ? (a[i - 1] + step - n >= n? group[a[i - 1] + step - n - n] : group[a[i - 1] + step - n]) : group[a[i - 1] + step]);
        int cur = (a[i] + step >= n ? (a[i] + step - n >= n? group[a[i] + step - n - n] : group[a[i] + step - n]) : group[a[i] + step]);
        new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
      }
    }
    swap(group, new_group);
    step <<= 1;
  }
  return a;
}
