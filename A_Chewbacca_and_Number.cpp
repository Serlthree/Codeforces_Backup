#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll a;
  cin >> a;
  ll b = 0, c = 1;
  while(a){
    ll d = a % 10;
    if(d > 4 && a != 9){
      d = 9 - d; 
    }
    b += d * c;
    a /= 10;
    c *= 10;
  }
  cout << b << endl;
}