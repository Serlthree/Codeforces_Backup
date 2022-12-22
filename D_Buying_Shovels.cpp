#include <iostream>
using ll = long long;
using namespace std;
void solve(){
  ll n, m, mx = -1;
  cin >> n >> m;
  // find least factor of n
  if(n <= m) cout << 1 << "\n";
  else{
    int i = 2;
    while(i*i <= n){
      if(n%i == 0){
        if(n <= m * i) {cout << i << "\n"; return;}
        else if(m >= i) mx = n/i;
      }
      i++;
    }
    if(mx != -1) cout << mx << "\n";
    else cout << n << "\n";
  }
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}