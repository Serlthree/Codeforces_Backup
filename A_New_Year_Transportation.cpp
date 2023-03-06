#include <bits/stdc++.h>
using namespace std;
int n, t, x, s = 1;
int main(){
  cin >> n >> t;
  for(int i = 1; i <= n; i++){
    cin >> x;
    if(s == i){
      s += x;
    }
    if(s == t){
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}