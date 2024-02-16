#include <bits/stdc++.h>
#define ld long double
using namespace std;
const ld PI = acos(-1);
int n;
ld x, y;
pair<ld,int> s[200005]; //stores the angle and the index
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> x >> y;
    ld ang = atan2(y,x);
    //if(ang < 0) ang += 2*PI;
    s[2*i-1] = {ang,i};
    s[2*i] = {ang+2*PI,i};
  }
  sort(s+1,s+2*n+1);
  ld ans = 1e9;
  int a, b;
  for(int i = 1; i < 2*n; i++){
    ld d = s[i+1].first-s[i].first;
    if(d < ans){
      ans = d;
      a = s[i].second;
      b = s[i+1].second;
    }
  }
  cout << a << " " << b;
}