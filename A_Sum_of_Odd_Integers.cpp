#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll t, n, k;
  cin >> t;
  while(t--){
    cin >> n >> k;
    if(n >= k * k){
      if(n % 2 == k % 2){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
    else{
      cout << "NO" << endl;
    }
  }
}