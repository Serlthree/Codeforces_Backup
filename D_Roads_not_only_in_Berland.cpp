#include <bits/stdc++.h>
using namespace std;

int uf[1001];
vector<pair<int, int>> useless_roads;
int Find(int u){
  if(uf[u] == u) return u;
  return uf[u] = Find(uf[u]);
}
bool Union(int u, int v){
  int x = Find(u);
  int y = Find(v);
  if(x != y) {
    uf[x] = y;
    return true;
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) uf[i] = i;
  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    if(!Union(a,b)){
      useless_roads.push_back({a,b});
    }
  }
  //default set would be at 1
  cout << useless_roads.size() << '\n';
  for(int i = 2; i <= n; i++){
    if(Find(i) != Find(1)){
      cout << useless_roads.back().first << ' ' << useless_roads.back().second << ' ' << 1 << ' ' << i << '\n';
      useless_roads.pop_back();
      Union(i,1);
    }
  }
}