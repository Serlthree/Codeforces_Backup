#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, k;
  cin >> n >> k;
  unordered_set<int> s;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    s.insert(x);
  }
  if(s.size() > k){
    cout << -1 << "\n";
  }
  //print array
  else{
    cout << n * k << "\n";
    for(int i = 0; i < n; i++){
      for(auto x : s){
        cout << x << " ";
      }
      for(int j = 0; j < k - s.size(); j++){
        cout << 1 << " ";
      }
    }
    cout << "\n";
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}