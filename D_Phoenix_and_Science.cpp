#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin >> n;
  //minimum number is always going to be log(n)
  int d = __lg(n);
  cout << d << '\n';
  int num = 1;
  n--;
  for(int i = 0; i < d; i++){
    int l = 0, r = num;
    //binary search for original n
    int rem = d - i;
    while(l <= r){
      int mid = (l + r) / 2;
      if(rem*(num+mid) <= n){
        //cout << rem * (num + mid) << ' ';
        //cout << num + mid << ' ';
        l = mid + 1;
      }
      else{
        //cout << num + mid << ' ';
        r = mid - 1;
      }
      //cout << num + mid << ' ';
    }
    //cout << '\n' << l << ' ' << r;
    //take r
    //cout << '\n';
    cout << r << ' ';
    num += r;
    n -= num;
    //break;
  }
  cout << '\n';
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