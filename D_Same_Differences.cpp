#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
int t, n, x;
int main(){
  cin >> t;
  while(t--){
    cin >> n;
    m.clear();
    long long ans = 0;
    for(int i = 0; i < n; i++){
      cin >> x;
      m[x - i]++;
      ans += m[x - i] - 1;
    }
    cout << ans << endl;
  }
}