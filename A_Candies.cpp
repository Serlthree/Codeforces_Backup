#include <bits/stdc++.h>
using namespace std;
int t, pw2, n;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    pw2 = 4;
    while(n%(pw2-1)!=0) pw2 *= 2;
    cout << n/(pw2-1) << "\n";
  }
}