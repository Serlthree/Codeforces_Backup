#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q, a[N], b[N], l, r;
int main(){
  //O(n) range updates (no seg tree needed)
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  while(q--){
    cin >> l >> r;
    b[l]++;
    b[r + 1]--;
  }
  //prefix sum
  for(int i = 1; i <= n; i++){
    b[i] += b[i - 1];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    ans += 1LL * a[i] * b[i];
  }
  cout << ans << endl;
}