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
#define vi vector<int>
#define se second
#define fi first
#define si(x) scanf("%d",&x)
#define sf scanf
#define pf printf

int n;
ll ans, a[(int)2e5];
int main(){
	cin >> n;
	F0R(i,n){
		cin >> a[i];
		if(i >= 2) a[i] += a[i-2];
	}
	ans = max(a[n-1],a[n-2] + a[0]);
	F0R(i,n-2){
		if(i%2){
			ans = max(ans,a[n-1] - a[i] + a[i+1]);
		}
		else{
			ans = max(ans,a[n-2] - a[i] + a[i+1]);
		}
	}
	cout << ans;
	return 0;
}
/*
9 0 7 6 5 6 6
9 0 16 6 21 12 27
27, 21, 27-9+0=18, 12-0+16=28, 27-16+6=18, 12-6+21=28, 27-21+12=18

How will this greedy implemenetation fail?
How fast this greedy implementation?
About O(n^2-2n) time?

almost factorial speed

Could maybe precompute this
precompute the sum of all evens and the sum of all odds
subtract evens add odds and vise versa

There's no negatives it's always optimal to add the max
*/