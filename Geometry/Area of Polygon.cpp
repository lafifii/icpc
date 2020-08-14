struct point{
	int x, y;
};
// Poligono Regular -> apotema*perimetro/2
const double pi = acos(-1);
double apotema(int n, float a) 
{ 
    return a/(2 * tan((180.0/n)*pi/ 180)); 
} 
double areaPR(int n, float a){
	return ((n*a)/2.0)*apotema(n,a); 
}
// Poligono Irregular
int area2(point a, point b, point c){ 
	return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
}
int areaPI(int n, vector<point>& P){
	// P -> ordenado en sentido antihorario
	int s = 0;
	for(int i = 1; i < n - 1; ++i)
		s+= area2(P[0], P[i], P[i + 1]);
	return s/2;
}
