#include <bits/stdc++.h>
using namespace std;

int t, x_1, x_2, y_1, y_2;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  //impossible to have the exact same sum
  while(t--){
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    //figure out the formula
    cout << 1LL * (x_2 - x_1) * (y_2 - y_1) + 1 << endl;
  }
}