#include <bits/stdc++.h>
using namespace std;

// try dp dp[x][y][0] = length, dp[x][y][1] = merge left, dp[x][y][2] = merge right
int dp[501][501][3], a[501];
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  for(int i = n - 1; i >= 0; i--){
    for(int j = i; j < n; j++){
      if(i == j){
        dp[i][j][0] = 1;
        dp[i][j][1] = a[j];
        dp[i][j][2] = a[j];
      }
      //simulate merging
      else if(i + 1 == j){
        if(a[i] == a[j]){
          dp[i][j][0] = 1;
          dp[i][j][1] = a[i] + 1;
          dp[i][j][2] = a[i] + 1;
        }
        else{
          dp[i][j][0] = 2;
          dp[i][j][1] = a[i];
          dp[i][j][2] = a[j];
        }
      }
      else{
        for(int k = i; k < j; k++){
          if(dp[i][k][2] == dp[k+1][j][1] && dp[i][j][0] > dp[i][k][0] + dp[k+1][j][0] - 1){
            dp[i][j][0] = dp[i][k][0] + dp[k+1][j][0] - 1;
            //updates 2
            dp[i][j][2] = dp[k+1][j][2];
            if(dp[k+1][j][0] == 1) dp[i][j][2]++;
            //updates 1
            dp[i][j][1] = dp[i][k][1];
            if(dp[i][k][0] == 1) dp[i][j][1]++;
          }
          else if (dp[i][j][0] > dp[i][k][0] + dp[k+1][j][0]){
            dp[i][j][0] = dp[i][k][0] + dp[k+1][j][0];
            dp[i][j][1] = dp[i][k][1];
            dp[i][j][2] = dp[k+1][j][2];
          }
          /*if(i == 1 && j == 4){
            cout << k << " " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << endl;
          }*/
        }
      }
    }
  }
  /*for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(dp[i][j][0] != 0x3f3f3f3f) cout << dp[i][j][0] << " ";
      else cout << "x ";
    }
    cout << endl;
  }*/
  cout << dp[0][n-1][0];
}