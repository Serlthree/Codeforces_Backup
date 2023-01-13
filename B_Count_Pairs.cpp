#include <bits/stdc++.h>
using namespace std;
long long n, p, k, a, ans, sqra;
map<long long,int> mp;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p >> k;
  for(int i = 0; i < n; i++){
    cin >> a;
    //get to form a^4 - ka
    sqra = a*a % p;
    sqra = (sqra * sqra) % p;
    sqra = (sqra - (k*a)%p + p) % p;
    //cout << sqra << " ";
    ans += mp[sqra];
    mp[sqra]++;
  }
  cout << ans;
}