#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, q, a, b, t, uf[N], dis1[N], dis2[N];
vector<int> tree[N];
int find(int x){
  if(uf[x] == x){
    return x;
  }
  return uf[x] = find(uf[x]);
}
void dfs(int x){
  uf[x] = a;
  for(int i : tree[x]){
    if(uf[i] == 0){
      dfs(i);
      //finds total distance
      dis1[x] = max(dis1[x], max(dis1[i],dis2[i] + dis2[x] + 1));
      //finds max distance
      dis2[x] = max(dis2[x], dis2[i] + 1);
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(uf[i] == 0){
      a = i;
      dfs(i);
    }
  }
  for(int i = 0; i < q; i++){
    cin >> t >> a;
    //maximum path
    if(t == 1){
      cout << dis1[find(a)] << "\n";
    }
    //union
    if(t == 2){
      cin >> b;
      a = find(a);
      b = find(b);
      if(a != b){
        uf[a] = b;
        dis1[b] = max(max(dis1[b], dis1[a]), (dis1[a]+1)/2+(dis1[b]+1)/2+1);
      }
    }
  }
}