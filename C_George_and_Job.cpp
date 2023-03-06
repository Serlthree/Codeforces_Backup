#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long pre[5005], dp[5005][5005];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    pre[i] = pre[i - 1] + x;
  }
  for(int i = 1; i <= n - m + 1; i++){
    dp[i][1] = max(dp[i-1][1], pre[i + m - 1] - pre[i - 1]);
    for(int j = 2; j <= k; j++){
      if(i - m >= 0) dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + pre[i + m - 1] - pre[i - 1]);
    }
  }
  // debug purpose
  /*for(int i = 1; i <= n - m + 1; i++){
    for(int j = 1; j <= k; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[n - m + 1][k];
}