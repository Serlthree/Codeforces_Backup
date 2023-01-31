#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int n, x, y, ans[MAX], mx[MAX];
vector<int> tree[MAX];
map<int, int> mp[MAX];
// see Lomsat gelral
void dfs(int curr, int prev, int depth = 0){
  mp[curr][depth]++;
  mx[curr] = 1;
  //ans curr default = 0
  for(int nex : tree[curr]){
    if(nex == prev) continue;
    dfs(nex, curr, depth + 1);
    // swap to reduce complexity
    if(mp[nex].size() > mp[curr].size()) {
      swap(mp[nex], mp[curr]);
      mx[curr] = mx[nex];
      ans[curr] = ans[nex] + 1;
    }
    // merge
    for(auto it : mp[nex]){
      mp[curr][it.first] += it.second;
      if(mp[curr][it.first] > mx[curr] || (mp[curr][it.first] == mx[curr] && it.first - depth < ans[curr])){
        mx[curr] = mp[curr][it.first];
        ans[curr] = it.first - depth;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n -1; i++){
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
}