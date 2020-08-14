struct point{
	int x, y;
};
int area2(point a, point b, point c){
	return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
}
bool colinear(point a, point b, point c){
	return area2(a,b,c) == 0; 
}
bool within(int p, int q, int r){
	return (p <= q & q <= r) | (r <= q and q <= p);
}
// point c in segment ab
bool is_on(point a, point b, point c){
	if(not colinear(a,b,c)) return false;
	else if(a.x != b.x)
		return within(a.x,c.x,b.x);
	return within(a.y, c.y, b.y);
}
