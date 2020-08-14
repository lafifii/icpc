struct point{
	int x, y, id;
};
const int maxn = 1e4;
const double pi = acos(-1);

point P[maxn];

int n;
double dis(point a, point b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool angulo(point a, point b, point c){
	point ab,bc;
	
	ab.x = b.x - a.x;
    ab.y = b.y - a.y;

    bc.x = c.x - b.x;
    bc.y = c.y - b.y;

    float dotabbc = (ab.x * bc.x + ab.y * bc.y);
    float lenab = sqrt(ab.x * ab.x + ab.y * ab.y);
    float lenbc = sqrt(bc.x * bc.x + bc.y * bc.y);
    
	return acos(dotabbc/(lenab*lenbc)) < pi;
}
typedef pair<point,point> line;
bool cmp(point a, point b){ // decreasing y
	if(a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}
bool ady(point a, point b){
	return (a.id + 1)%n == b.id or (b.id + 1)%n == a.id;
}
vector<line> triangulateMonotone(){

	for(int i = 0; i < n; ++i) P[i].id = i;
	sort(P, P + n, cmp);
	
	deque<point> s; 
	vector<line> D;
	s.push_back(P[0]);
	s.push_back(P[1]);
	for(int i = 2; i < n; ++i){
		bool a1 = ady(P[i],s.back());
		bool a2 = ady(P[i],s.front());
		if(a1 && !a2){
			while(s.size() > 1){
				point st = s.back(); s.pop_back();
				point st1 = s.back(); s.push_back(st);
				if(not angulo(P[i],st,st1)) break;
				s.pop_back();
				D.push_back({P[i], st1});
			}
			s.push_back(P[i]);
		}
		else if(!a1 && a2){
			point aux = s.back();
			while(s.size() > 1){
				D.push_back({P[i],s.back()});
				s.pop_back();
			}
			s.pop_back();
			s.push_back(aux);
			s.push_back(P[i]);
		}
		else{
			s.pop_back();
			while(s.size() > 2){
				D.push_back({P[i],s.back()});
				s.pop_back();
			}
		}
	}
	return D;
}
