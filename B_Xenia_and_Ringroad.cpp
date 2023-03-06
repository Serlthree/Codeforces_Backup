#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, ans, cur, pre = 1;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> cur;
    if(cur >= pre){
      ans += cur - pre;
    }
    else{
      ans += n + cur - pre;
    }
    pre = cur;
  }
  cout << ans;
}