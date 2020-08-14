struct point{
	int x, y;
};
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
// counterclockwise
