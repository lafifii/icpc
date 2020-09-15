template<typename T> 
vector<pt<T>> convex_hull(vector<pt<T>>& pts){ 
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	int m = pts.size();
	if (m == 1) return { pts[0] };
	vector<pt<T>> upper, lower;
	int lu = 0, lo = 0; 
	for(int i = 0; i<m; i++){
		while (lu >= 2 && (upper[lu-2] - upper[lu-1]) % (pts[i] - upper[lu-1]) <= 0) {
			upper.pop_back(); 
			lu--;
		}
		upper.emplace_back(pts[i]), lu++;
		while (lo >= 2 && (lower[lo-2] - lower[lo-1]) % (pts[i] - lower[lo-1]) >= 0){
			lower.pop_back(); 
			lo--;
		}
		lower.emplace_back(pts[i]), lo++;
	}
	reverse(upper.begin(), upper.end()); 
	lower.pop_back();
	lower.insert(lower.end(), upper.begin(), upper.end()); 
	lower.pop_back(); 
	return lower; 
}
