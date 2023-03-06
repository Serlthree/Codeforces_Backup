#include <bits/stdc++.h>
using namespace std;

bool dp[13000];
int main(){
  int t;
  cin >> t;
  dp[11] = true;
  dp[111] = true;
  for(int i = 0; i < 12000; i++){
    if(dp[i]){
      dp[i+11] = true;
      dp[i+111] = true;
    }
  }
  while(t--){
    int x;
    cin >> x;
    if(x >= 11110){
      cout << "YES\n";
    }
    else if(dp[x]){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}