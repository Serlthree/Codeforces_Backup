#include <bits/stdc++.h>
using namespace std;

long long n, p, w, d, y;
int main(){
  cin >> n >> p >> w >> d;
  //brute force solution the easiest
  //takes advantage of the fact that w > d
  //so we can brute force the number of draws (because constraints means that 1e6 draws is the max)
  for(y = 0; y <= 1e6; y++){
    long long x = (p - y * d) / w;
    if(x >= 0 && x + y <= n && x * w + y * d == p){
      cout << x << " " << y << " " << n - x - y;
      return 0;
    }
  }
  cout << -1;
}