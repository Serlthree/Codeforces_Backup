#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, top[N], a[N];
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> top[i];
    top[i] -= a[i];
    top[i] = -top[i];
  }
  sort(top, top + n);
  long long ans = 0;
  for(int i = 0; i < n; i++){
    int x = upper_bound(top, top + n, -top[i]) - top;
    //cout << top[i] << " ";
    //cout << x << " ";
    ans += n - x;
    //removing self pairs
    if(i > x) ans--;
  }
  cout << ans/2 << endl;
}