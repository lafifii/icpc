// gracias raxo
// Lexicographically minimum suffix array & LCP array construction
// SA: O(nlogn), LCP: O(n)

vector<int> suffix_array(vector<int> &s, int char_bound = -1) {
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
		for(int i = 0; i < n; i++){
			sorted_by_second[at++] = a[i] - step < 0? a[i] - step + n : a[i] - step;
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
				int pre = (a[i - 1] + step >= n ? group[a[i - 1] + step - n] : group[a[i - 1] + step]);
				int cur = (a[i] + step >= n ? group[a[i] + step - n] : group[a[i] + step]);
				new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
			}
		}
		swap(group, new_group);
		step <<= 1;
	}
	sort(a.begin(),a.end(),[&](int i, int j){
		if(group[i] == group[j]) return i < j;
		return group[i] < group[j];
	});
	return a;
}

vector<int> lcp_construction(vector<int> &s, vector<int> &a){
	int n = s.size();
	vector<int> rank(n, 0);
	for(int i=0; i<n; i++){
		rank[a[i]] = i;
	}
	int k = 0;
	vector<int> lcp(n-1,0);
	for(int i=0; i<n; i++){
		if(rank[i] == n-1){
			k = 0;
			continue;
		}
		int j = a[rank[i]+1];
		while(i + k < n and j + k < n and s[i + k] == s[j + k]) k += 1;
		lcp[rank[i]] = k;
		if(k > 0) k -= 1;
	}
	return lcp;
}
