const int maxn = 1e3, oo = 1e5;
struct point{
	int x, y;
};
point P[maxn];
int area2(point a, point b, point c){
	return ((a.x - c.x) * (b.y - c.y)) - ((a.y - c.y) * (b.x - c.x));
}
bool izquierdaOn(point a, point b, point c){
	return area2(a,b,c) > 0;
}
bool izquierda(point a, point b, point c){
	return area2(a,b,c) >= 0;
}
bool colinear(point a, point b, point c){
	return area2(a,b,c) == 0; 
}
bool entre(point a, point b, point c){
	if(not colinear(a,b,c)) return false;
	else if(a.x != b.x)
		return (a.x <= c.x && c.x <= b.x) || (a.x >= c.x && c.x >= b.x);
	return (a.y <= c.y && c.y <= b.y) | (a.y >= c.y and c.y >= b.y);
}
bool intersectaP(point a, point b, point c, point d){
	if(colinear(a,b,c) or colinear(a,b,d)) return false;
	if(colinear(c,d,a) or colinear(c,d,b)) return false;
	bool e1 = izquierdaOn(a,b,c) ^ izquierdaOn(a,b,d);
	bool e2 = izquierdaOn(c,d,a) ^ izquierdaOn(c,d,b);
	return (e1 && e2);
}
bool intersecta(point a, point b, point c, point d){
	if(intersectaP(a,b,c,d)) return true;
	return (entre(a,b,c) || entre(a,b,d) || entre(c,d,a) || entre(c,d,b));
}
bool insideT(point pt){
	int A = area2(P[0],P[1],P[2]);
	int a1 = area2(pt,P[0],P[1]);
	int a2 = area2(pt,P[1],P[2]);
	int a3 = area2(pt,P[2],P[0]);
	return (a1 + a2 + a3 == A);
}
bool insideP(int n, point pt){
	if(n == 3) return insideT(pt);
	int cont = 0;
	point fin = {oo, pt.y};
	for(int i = 0; i < n; ++i){
		if(intersecta(P[i],P[(i+1)%n],pt,fin)){
			if(colinear(P[i],P[(i+1)%n],pt))
				return entre(P[i],P[(i+1)%n],pt);
			++cont;
		}
	}
	return cont&1; 
}
// Ray Tracing
