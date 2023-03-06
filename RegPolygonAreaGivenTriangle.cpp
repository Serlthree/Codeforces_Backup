//Minimum Angle Needed:
/*
Triangle: 60-60-60 (Take 180/3)
Square: 45-45-90 (Take 180/4)
Pentagon: 108-36-36 or 72-72-36 (Take 180/5)
Hexagon: 120-30-30 or 30-60-90 (Take 180/6)


This uses ealg to find the gcd of all three angles
*/

#include <bits/stdc++.h>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
const double pi = 3.141592653589793238;
const int INF = 1000000000;
 
#define mii map<int,int>
#define ld long double
#define ll long long
#define pb push_back
#define mp make_pair
#define F0R(i,j) for(int i = 0; i < (int)j; i++)
#define FOR(i,j,k) for (int i = j; i < (int)k; i++)
#define FORE(i,j,k) for(int i = j; i <= (int)k; i++)
#define FORN(i, n) for(int i=(n)-1; i>=0; i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vi vector<int>
#define se second
#define fi first
#define si(x) scanf("%d",&x)
#define sf scanf
#define pf printf

double dform(double x, double y, double x2, double y2) {
	return sqrt(sqr(x - x2) + sqr(y - y2));
}
double loc(double a, double b, double c) {
	//c^2 = a^2 + b^2 - 2*a*b*cos(C)
	double cosc = (sqr(a) + sqr(b) - sqr(c)) / (2 * a * b);
	return acos(cosc);
}
double heron(double a, double b, double c) {
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
double ealg(double a, double b) {
	while (a > 1e-4 && b > 1e-4) {
		if (a > b) {
			a -= floor(a / b) * b;
		}
		else {
			b -= floor(b / a) * a;
		}
	}
	return a + b;
}
double ax, ay, bx, by, cx, cy, mang, a, b, c, A, R, ang1, ang2, ang3, s, ans;
int main() {
	cout << setiosflags(ios::fixed) << setprecision(6);
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	a = dform(ax, ay, bx, by);
	b = dform(bx, by, cx, cy);
	c = dform(ax, ay, cx, cy);
	A = heron(a, b, c);
    //Circumradius of a Triangle Formula (abc) / sqrt((a + b + c)(b + c - a)(c + a - b)(a + b - c))
	R = (a * b * c) / (4.0 * A);
	ang1 = loc(a, b, c);
	ang2 = loc(a, c, b);
	ang3 = loc(b, c, a);
	mang = ealg(ang1, ang2);
	mang = ealg(mang, ang3);
	s = pi / mang;
    //Area of a Regular Polygon with Circumradius = (1/2) nr^2sin(2pi/n)
	ans = s / 2.0 * R * R * sin(2.0 * pi / s);
	cout << ans;
}