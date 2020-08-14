typedef pair<int,int> pt;
#define x first
#define y second
const double oo = 1e9;
bool cmpx(pt a, pt b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool cmpy(pt a, pt b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
int n;
double dis(pt a, pt b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double bruteForce(pt P[], int n)  
{  
    double mini = oo;  
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n; ++j)  
           mini = min(mini, dis(P[i], P[j]));  
    return mini;  
}  
double stripc(pt strip[], int size, double d)  
{  
    double mini = d;
    sort(strip, strip + size, cmpy);  
    for (int i = 0; i < size; ++i)  
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < mini; ++j)  
            mini = min(mini,dis(strip[i], strip[j]));  
    return mini;  
}  
double closest(pt P[], int n)  
{  
    if (n <= 3)  
        return bruteForce(P, n);  
    int mid = n/2;  
    pt midpt = P[mid];  
    double dl = closest(P, mid);  
    double dr = closest(P + mid, n - mid);  
    double d = min(dl, dr);  
    pt strip[n];  
    int j = 0;  
    for(int i = 0; i < n; i++)  
        if (abs(P[i].x - midpt.x) < d)  
            strip[j] = P[i], j++;  
    return min(d, stripc(strip, j, d));  
}  
double solve(pt P[], int n)  
{  
    sort(P, P + n, cmpx);  
    return closest(P, n);  
}  
//O(n(logn)^2))
