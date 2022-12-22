#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, d;
//struct didn't matter
struct Friend{
  int m, s;
} friends[100005];
bool cmp(Friend a, Friend b){
  return a.m < b.m;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> friends[i].m >> friends[i].s;
  }
  sort(friends + 1, friends + n + 1, cmp);
  //two pointers
  int l = 1, r = 1;
  ll ans = 0;
  ll cur = 0;
  while(r <= n){
    cur += friends[r].s;
    while(friends[r].m - friends[l].m >= d){
      cur -= friends[l].s;
      l++;
    }
    r++;
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}