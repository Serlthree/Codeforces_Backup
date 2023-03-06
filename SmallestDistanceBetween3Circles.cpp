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
#define pdd pair<ld,ld>
#define vi vector<int>
#define se second
#define fi first
#define si(x) scanf("%d",&x)
#define sf scanf
#define pf printf
#define quick ios::sync_with_stdio(false)
#define precision(x) cout << setiosflags(ios::fixed) << setprecision(5);
double x[3], y[3], r[3], xans, yans, adjuster=1, dform[3], res, cnt;
double F(double x1, double y1){
	res = 0;
	//Do a modified distance formula to account for the radius
	F0R(i,3){
		dform[i] = sqrt(sqr(x1-x[i])+sqr(y1-y[i]))/r[i];
	}
	/*use the "distance/std dev" formula again to find whether or not it's closer to the center
	Sqrts will cancel themselves anyways
	*/
	F0R(i,3){
		res += sqr(dform[i] - dform[(i+1)%3]);
	}
	return res;
}
int main(){
    quick;
	precision(5);
	F0R(i,3){
		cin >> x[i] >> y[i] >> r[i];
	}
	//Use approximation to solve this: First is inital guess (median)
	F0R(i,3){
		xans += x[i]/3, yans += y[i]/3;
	}
	//the while loop
	while(adjuster > 1e-6){
		if(F(xans,yans) > F(xans+adjuster,yans)) xans += adjuster;
		else if(F(xans,yans) > F(xans-adjuster,yans)) xans -= adjuster;
		else if(F(xans,yans) > F(xans,yans+adjuster)) yans += adjuster;
		else if(F(xans,yans) > F(xans,yans-adjuster)) yans -= adjuster;
		else adjuster *= .5;
		cnt++;
		//cout << adjuster << " ";
		//adjuster needs to stay until work is done (we will account for)
		//You have to do the adjuster constant at a .7 to not get TLE'd?
	}
	if(F(xans,yans) < 1e-5)cout << xans << " " << yans << endl;
	cout << cnt;
}
/*
Same distance can be found really easily
Find the distance with the same angle and the same distance from every other thing.
*/