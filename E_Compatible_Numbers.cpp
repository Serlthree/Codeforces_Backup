#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 22) - 1;
int dp[N], n, a[N];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++){
    cin >> a[i];
    dp[a[i]^N] = a[i];
  }
  //dp
  for(int i = N - 1; i >= 0; i--){
    if(dp[i] != -1){
      for(int j = 0; j <= 22; j++){
        //if bit is set
        if(i & (1 << j)){
          dp[i ^ (1 << j)] = dp[i];
        }
      }
    }
  }
  //queries
  for(int i = 0; i < n; i++){
    cout << dp[a[i]] << " ";
  }
}
