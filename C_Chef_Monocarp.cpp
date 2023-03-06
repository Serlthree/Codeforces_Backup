#include <bits/stdc++.h>
using namespace std;
int q, ans, n, t[205], dp[205];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  while(q--){
    memset(dp, 0x3f, sizeof(dp));
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    sort(t+1, t+n+1);
    dp[0] = 0;
    //literally a knapsack problem
    for(int i = 1; i <= 2*n; i++){
      for(int j = n; j >= 1; j--){
        dp[j] = min(dp[j], dp[j-1] + abs(t[j] - i));
      }
    }
    cout << dp[n] << '\n';
  }
}