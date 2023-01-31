#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main(){
  cin >> a >> b;
  while(a <= b){
    a *= 3;
    b *= 2;
    ans++;
  }
  cout << ans;
}