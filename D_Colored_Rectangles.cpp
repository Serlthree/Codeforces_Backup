#include <bits/stdc++.h>
#define F0R(i,n) for(int i = 0; i < n; i++)
#define F0RB(i,n) for(int i = n; i >= 0; i--)
#define FOR(i,n,k) for(int i = n; i < k; i++)
#define FORO(i,n) for(int i = 1; i <= n; i++)
#define pii pair<int,int>
#define setprecision(x) cout << setiosflags(ios::fixed) << setprecision(x)
#define pb push_back
#define mp make_pair
#define fastIO std::ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ull = unsigned long long;
//precision error functions
template <typename T>
T frac_ceil(T a, T b){
  return (a+b-1)/b;
}
//Print tools
template <typename T> 
void printArr(T array[], int SIZE)
{
  for(int i = 0; i < SIZE; i++) std::cout << array[i] << " ";
}
//modulos
const int modulo = 1e8;
//infinity
const int INF = 1e9;
const long long LINF = INT64_MAX;
//Direction helpers
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
#define checkBounds(x,n) x >= 0 && x < n
using namespace std;

const int MAX = 205;
int R, G, B, r[MAX], b[MAX], g[MAX];
ll dp[MAX][MAX][MAX], comp;
int main(){
  fastIO;
  cin >> R >> G >> B;
  FORO(i,R) cin >> r[i];
  FORO(i,G) cin >> g[i];
  FORO(i,B) cin >> b[i];
  //combine greedy + dp
  sort(r+1,r+R+1);
  sort(g+1,g+G+1);
  sort(b+1,b+B+1);
  //dp
  //emset(dp,-1,sizeof(dp));
  F0RB(i,R){
    F0RB(j,G){
      F0RB(k,B){
        ll &curr = dp[i][j][k];
        curr = max(curr,dp[i+1][j+1][k]+r[i+1]*g[j+1]);
        curr = max(curr,dp[i+1][j][k+1]+r[i+1]*b[k+1]);
        curr = max(curr,dp[i][j+1][k+1]+g[j+1]*b[k+1]);
        comp = max(curr,comp);
      }
    }
  }
  cout << comp;
}
