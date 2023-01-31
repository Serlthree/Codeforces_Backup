#include <bits/stdc++.h>
using namespace std;
//greedy solution (checkerboard)
int n, m, x;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> x;
      if((i + j) % 2 == 0){
        cout << 720720 << ' ';
      }
      else{
        cout << 720720 + x * x * x * x << ' ';
      }
    }
    cout << '\n';
  }
}