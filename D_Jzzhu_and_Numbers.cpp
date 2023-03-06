#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, mod = 1e9 + 7;
int n, x, a[N+5], f[N+5];
long long ans;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> x;
    f[x]++; 
  }
  a[0] = 1;
  for(int i = 1; i <= n; i++){
    //calculate powers of 2
    a[i] = (a[i-1]<<1)%mod;
  }
  for(int j = 0; j < 20; j++){
    for(int i = N; i >= 0; i--){
      if(i&(1<<j)){
        (f[i^(1<<j)] += f[i])%=mod;
      }
    }
  }
  for(int i = N; i >= 0; i--){
    x = 1;
    for(int j = 0; j < 20; j++){
      if(i&(1<<j)) x = -x;
    }
    (ans += 1LL*x*(a[f[i]]-1))%=mod;
  }
  cout << (ans+mod)%mod << endl;
}
/*
The idea for the algorithm
-0 = total number of groups that can be xored to 0 or more = a1
-1 = total number of groups that can be xored to 1 or more = a2 
(our bit calcs work because the groups have to share a common bit)
-Therefore we should subtract the groups that can be xored to 1 or more because 
we want groups that can be xored to exactly 0

However, we would overcount the groups that have 2 bits (would be subtracted twice)
so we add them back on
*/