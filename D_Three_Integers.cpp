#include <bits/stdc++.h>
using namespace std;

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  int ans = INT32_MAX, x, y, z;
  int cnt = 0;
  for(int i = 1; i <= 13000; i++){
    //should be approx n * ln^2(n)
    for(int j = i; j <= 13000; j += i){
      for(int k = j; k <= 13000; k += j){
        if(abs(a - i) + abs(b - j) + abs(c - k) < ans){
          ans = abs(a - i) + abs(b - j) + abs(c - k);
          x = i, y = j, z = k;
        }
        cnt++;
      }
    }
  }
  cout << ans << '\n';
  cout << x << ' ' << y << ' ' << z << '\n';
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  /*
  Proof of time complexity:
  Note 1 1 1 - 1 1 n has n number of cases
  Then 1 2 2 - 1 2 n has n/2 number of cases 
  So therefore the formulae would be n + n/2 + n/3 + n/4 + ... + n/n = n * log(n)
  Noting that 2 numbers gives n log(n) cases, 3 numbers gives n log^2(n) cases
  */
}