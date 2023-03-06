#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, pre[MAX], j, cnt, dp[MAX], x;
vector<pair<int,int>> ans;
string s;
int main(){
  //should be a KMP prefix problem
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n = s.length();
  //prefix function (longest proper prefix that is also a suffix)
  for(int i = 1; i < n; i++){
    j = pre[i-1];
    while(j > 0 && s[i] != s[j]) j = pre[j-1];
    if(s[i] == s[j]) j++;
    pre[i] = j;
  }
  //debug prefix function
  //for(int i = 0; i < n; i++) cout << pre[i] << " ";
  dp[pre[n-1]]++; 
  for(int i = 0; i < n; i++){
    x = pre[i];
    dp[x]++;
  }
  for(int i = n - 1; i >= 0; i--){
    dp[pre[i-1]] += dp[i];
  }
  x = pre[n-1];
  ans.push_back({n, 1});
  while(x > 0){
    //counts the prefix
    ans.push_back({x, dp[x]});
    x = pre[x-1];
  }
  //debug dp
  //for(int i = 0; i <= n; i++) cout << dp[i] << " ";
  cout << ans.size() << endl;
  for(int i = ans.size()-1; i >= 0; i--){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}