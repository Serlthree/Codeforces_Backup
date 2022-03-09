#include <bits/stdc++.h>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
const double pi = 3.141592653589793238;
const int INF = 1e9;

#define quick ios::sync_with_stdio(false); cin.tie(0) 
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
//NOTE: Ordering of functions matters
int n, m, k;
int a[71][71], dp[71][71][36][71];
int main(){
	quick;
	cin >> n >> m >> k;
	F0R(i,n){
		F0R(j,m){
			cin >> a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0][0] = 0;
	F0R(i,n){
		F0R(j,m){
			F0R(cnt, m/2 + 1){
				F0R(rem, k){
					if(dp[i][j][cnt][rem] == -1) continue;
					int nexti = (j == m-1? i + 1 : i); //finds the next row
					int nextj = (j == m-1? 0: j + 1); //finds the next column
					if(nexti != i+1){
						//carryover portion of the 0-1 knapsack
						checkmax(dp[nexti][nextj][cnt][rem], dp[i][j][cnt][rem]);
					} else{
						checkmax(dp[nexti][nextj][0][rem], dp[i][j][cnt][rem]);
					}
					if(cnt + 1 <= m/2){
						//add portion of the 0-1
						if(nexti != i+1){
							checkmax(dp[nexti][nextj][cnt+1][(rem+a[i][j])%k], dp[i][j][cnt][rem] + a[i][j]);
						}else{
							checkmax(dp[nexti][nextj][0][(rem+a[i][j])%k], dp[i][j][cnt][rem]+a[i][j]);
						}
					}
				}
			}
		}
	}
	cout << max(0, dp[n][0][0][0]) << endl;
}
/*
3 4 3
1 2 3 4
5 2 2 2
7 1 1 4

Using a knapsack implementation:
dp[row][col][cnt][remainder]
cout << dp[n][0][0]

Check all previous dp[row][cols] (whatever that is)
Look all the previous [cnt][remainder], either add the current value or carry it over to
the next value

Knapsack Problem...

How to tell if it's a knapsack problem?
Has characteristics of the 0-1 Knapsack solution: 
Which is the 2 options, add or carry over
*/