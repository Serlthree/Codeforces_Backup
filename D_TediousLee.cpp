//very hard greedy + dp problem
#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6 + 5;
long long t, dp[MAX], n;
const long long mod = 1e9 + 7;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for(int i = 3; i < MAX; i++){
    dp[i] = (2*dp[i-2]%mod + dp[i-1]%mod + (i%3 == 0))%mod;
  }
  while(t--){
    cin >> n;
    cout << (4*dp[n])%mod << endl;
  }
}
/*
big intuition
RDB(5) is connected to 2 RDB(3) and 1 RDB(4)
then for the i%3 == 0 case, we note that we can pick the root node if the other nodes don't color the root
*/