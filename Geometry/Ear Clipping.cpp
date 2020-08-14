struct point{
	int x, y;
};
const int maxn = 1e4;
point P[maxn];
int n;
bool ear[maxn];
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
bool incone(int i, int j){
	int u = ((i - 1)+ n)%n, w = (i + 1)%n;
	if(izquierda(P[u], P[i],P[w])) 
		return izquierdaOn(P[i],P[j],P[u]) && izquierdaOn(P[j],P[i],P[w]); 
	return !(izquierda(P[i],P[j],P[w]) && izquierda(P[j],P[i],P[u]));
}
bool diagonal(int i, int j){
	for(int k = 0; k < n; ++k){
		int l = (k + 1)%n;
		if(k == i or k == j) continue;
		if(l == i or l == j) continue;
		if(intersecta(P[i],P[j],P[k],P[l])){
			return false;
			break;
		}
	}
	return incone(i,j) && incone(j,i);
}
void triangulacion(){
	for(int i = 0; i < n; ++i) ear[i] = diagonal((i - 1 + n)%n, (i + 1)%n);
	int i = 0;
	while(n > 3){
		for(; i < n and ear[i] == 0; ++i){} // buscar oreja
		
		printf("(%d,%d) y (%d,%d)\n",P[(i-1+n)%n].x,P[(i-1+n)%n].y,P[(i+1)%n].x,P[(i+1)%n].y);
		
		for(int j = i + 1; j < n; ++j){ 
			ear[j - 1] = ear[j];
			P[j - 1].x = P[j].x;
			P[j - 1].y = P[j].y;
		}
		
		n--;
		ear[i] = diagonal((i - 1 + n)%n, (i + 1)%n);
		ear[(i - 1 + n)%n] = diagonal((i - 2 + n)%n, i);
	}
}
