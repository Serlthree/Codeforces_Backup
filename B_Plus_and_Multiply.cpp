#include <bits/stdc++.h>
using namespace std;
long long t, n, a, b, n_mod, a_exp;
int cnt = 0;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--){
    //cnt++;
    cin >> n >> a >> b;
    n_mod = n % b;
    a_exp = 1;
    /*if(cnt == 1779){
      cout << n << "_" << a << "_" << b << "\n";
    }*/
    if(a == 1){
      if(n_mod == 1 || b == 1) cout << "Yes\n";
      else cout << "No\n";
      continue;
    }
    while(a_exp <= n){
      if(a_exp%b == n_mod){
        cout << "Yes\n";
        break;
      }
      a_exp *= a;
    }
    if(a_exp > n){
      cout << "No\n";
    }
  }
}