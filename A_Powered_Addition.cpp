#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, x, mx = -1e9, e = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> x;
      if(x >= mx){
        mx = x;
      }
      else{
        e = max(e,__lg(mx-x) + 1);
      }
    }
    //ans should be max(num operations, max element)
    cout << e << '\n';
  }
}