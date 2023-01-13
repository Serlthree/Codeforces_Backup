#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    ll x;
    cin >> x;
    if(__builtin_popcountll(x) == 1) cout << "NO\n";
    else cout << "YES\n";
  }
}