#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = INT64_MAX;

int a[2000];
ll ans;
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);
  //try index dp
  ll dp[n][n];
  memset(dp, 0x3f, sizeof(dp));
  for(int i = n; i >= 0; i--){
    for(int j = i; j < n; j++){
      if(i == j){
        dp[i][j] = 0;
      }
      else{
        dp[i][j] = min(dp[i][j], dp[i + 1][j] + a[j] - a[i]);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[j] - a[i]);
      }
    }
  }
  cout << dp[0][n - 1];
}