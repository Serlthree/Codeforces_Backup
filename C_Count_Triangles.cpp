#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
  cin >> a >> b >> c >> d;
  long long ans = 0;
  // i is the length of the longest side
  for(int i = max(c+1, a+b); i <= b + c; i++){
    // range of z * num of possible x and y
    ans += 1LL * (min(d+1,i)-c) * (min(i-b,b)-max(i-c,a)+1);
  }
  cout << ans;
}
/*
ridiculous algebric manipulation needed to solve this problem
i=x+y, a<=x<=b, b<=y<=c
a<=i-y<=b, c<=i-x<=d
From here we get 4 equations:
y <= i-a, y >= i-b, x >= i-c, x <= i-d
Note original equations are:
y <= c, y >= b, x <= b, x >= a

We can pick x or y to be the range
Note that x's range for example would be:
x >= max(i-c, a), x <= min(i-b, b) (because of stricter constraints)

Therefore range is
min(i-b, b) - max(i-c, a) + 1
*/