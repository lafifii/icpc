template<typename T> struct pt{ 
	T x, y;
	pt operator+(const pt& q){ return { x + q.x, y + q.y }; }
	pt operator-(const pt& q){ return { x - q.x, y - q.y }; }
	pt operator*(const T k){ return { x * k, y * k }; }
	T operator%(const pt& q) { return (x * q.y) - (y * q.x); }
	T len2() { return x*x + y*y; }
	T len() { return sqrt(len2()); }
	bool operator<(const pt&q) { return (x < q.x) || (x == q.x && y < q.y); }
	bool operator==(const pt&q) { return x == q.x && y == q.y; }
};
