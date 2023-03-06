#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], cnt[N], ind[N];
//TLE due to hashing collisions
map<int, int> mp;
int main(){
  //read it's consecutive
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int ans = n;
  for(int i = n; i >= 1; i--){
    mp[a[i]] = i;
    //also need to get all the indexes
    if(mp.count(a[i] + 1)){
      cnt[i] = cnt[mp[a[i] + 1]] + 1;
      ind[i] = mp[a[i] + 1];
    }
    else{
      cnt[i] = 1;
      ind[i] = i;
    }
    //store the index
    if(cnt[ans] < cnt[i]){
      ans = i;
    }
  }
  cout << cnt[ans] << '\n';
  while(ans <= n){
    cout << ans << ' ';
    if(ans == ind[ans]) break;
    ans = ind[ans];
  }
}