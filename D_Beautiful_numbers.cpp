#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll l, r, dp[20][2522][50];
int t, num[20], a[2522];
ll dfs(int dg, int rem, int mod, bool str_dec){
  if(dg == 0) return rem%mod==0;
  if(!str_dec && dp[dg][rem][a[mod]] != -1) return dp[dg][rem][a[mod]];
  int nxt = str_dec ? num[dg] : 9;
  ll ans = 0;
  for(int i = 0; i <= nxt; i++){
    ans += dfs(dg-1, (rem*10+i)%2520, i?mod/__gcd(mod,i)*i:mod, i == nxt && str_dec);
  }
  if(!str_dec) dp[dg][rem][a[mod]] = ans;
  return ans;
}
ll solve(ll x){
  ll dg = 0;
  while(x){
    num[++dg] = x%10;
    x /= 10;
  }
  return dfs(dg, 0, 1, true);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  for(int i = 1; i <= 2520; i++){
    //implement lcm
    if(2520%i == 0) a[i] = ++t;
  }
  cin >> t;
  while(t--){
    cin >> l >> r;
    cout << solve(r) - solve(l-1) << "\n";
  }
}
/*
Uses digit dp/compressing states dp by noting that
1. the digits can be stored by the modulus,
2. you can store the lcm of the numbers taken
3. you can add a strictly decreasing constraint so when you pick
the numbers == the digits in the original number, you can't exceed it

Then you can manually pick each digit and get the answer
*/