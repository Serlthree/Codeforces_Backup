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

int n, dp[101][3], a, pre = -1;
int main(){
  fastIO;
  cin >> n;
  F0R(i,n){
    cin >> a;
    if(i == 0){
      dp[0][0] = 1;
      if(a == 1 || a == 3) dp[0][1] = 0;
      else dp[0][1] = INF;
      if(a == 2 || a == 3) dp[0][2] = 0;
      else dp[0][2] = INF;
      pre = a;
      //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
      continue;
    }
    dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]) + 1;
    if(a == 0){
      dp[i][1] = INF;
      dp[i][2] = INF;
    }
    else if (a==1){
      //you can choose 1 or 0
      dp[i][1] = min(dp[i-1][0],dp[i-1][2]); 
      dp[i][2] = INF; //can't choose this
    }
    else if (a==2){
      dp[i][1] = INF; //can't choose this
      dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
    }
    else{
      dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
      dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
    }
    //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    pre = i;
  }
  cout << min(min(dp[n-1][0], dp[n-1][1]),dp[n-1][2]);
}
/*
1 3 3 2 1 2 3
1 1 1 1 1
0 1 0 F 
F 0 1 0
*/