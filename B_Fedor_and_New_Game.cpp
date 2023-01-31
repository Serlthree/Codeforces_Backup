#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m, k, a[N], f, ans;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) cin >> a[i];
  cin >> f;
  for(int i = 0; i < m; i++) {
    if(__builtin_popcount(f^a[i]) <= k) ans++;
  }
  cout << ans;
}