#include <bits/stdc++.h>
using namespace std;
int v, a[10], min_digit, digits;
string ans;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> v;
  for(int i = 1; i <= 9; i++) {
    cin >> a[i];
    if(i == 1 || a[i] <= a[min_digit]) {
      min_digit = i;
    }
  }
  digits = v/a[min_digit];
  v -= (v/a[min_digit])*a[min_digit];
  //subtract the min digit from all a
  for(int i = 9; i >= min_digit; i--) {
    a[i] -= a[min_digit];
  }
  for(int i = 1; i <= digits; i++) {
    bool flag = false;
    for(int j = 9; j > min_digit; j--){
      if(v >= a[j]){
        v -= a[j];
        ans.push_back(j + '0');
        flag = true;
        break;
      }
    }
    if(!flag) {
      ans.push_back(min_digit + '0');
    }
  }
  if(digits == 0) {
    cout << -1;
  } else {
    cout << ans;
  }
}