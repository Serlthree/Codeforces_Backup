#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <stack>
#include <iomanip>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
#define ld long double
#define ll long long
#define F0R(i,j) for(int i = 0; i < (int)j; i++)
#define FOR(i,j,k) for (int i = j; i < (int)k; i++)
#define FORE(i,j,k) for(int i = j; i <= (int)k; i++)
#define FORN(i, n) for(int i=(n)-1; i>=0; i--)
 
const ll INF = 1e18;
 
const int LIM = 4005;
 
int N;
int T[2010]; //time
int C[2010]; //value
ll dp[4010];
 
int main() {
	cin >> N;
	F0R(i, N) {
		cin >> T[i] >> C[i];
		T[i]++;
	}
	F0R(i, LIM + 1) {
		dp[i] = INF; //sets everything to infinite
	}
	dp[0] = 0;
	F0R(i, N) {
        //sets the current item
		for (int j = LIM; j >= T[i]; j--) { 
			checkmin(dp[j], dp[j - T[i]] + C[i]); 
		}
        /*F0R(i,N*2){
        	cout << dp[i] << " ";
        }
        cout << endl;*/
	}
	ll ans = INF;
	FORE(i,N,LIM){
		checkmin(ans, dp[i]); //finds the minimum cost
	}
	cout << ans;
}
/*
How the knapsack algorithm works:
4
2 10
0 20
1 5
1 3

0 INF INF 10 INF INF INF (2,10)
0 20 INF 10 20 INF INF (0,20)
0 20 5 10 30 15 35 INF (1,5)
0 20 3 10 8 13 33 18 (1,3)

*/