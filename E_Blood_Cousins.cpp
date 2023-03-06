#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5, LOG = 20;
int n, r, m, lift[MAX][LOG], v, p, depth[MAX], left_bounds[MAX], right_bounds[MAX], d;
vector<int> tree[MAX], node_depth[MAX];
//might be too much memory
void dfs(int curr, int prev, int dep = 0){
  depth[curr] = dep;
  node_depth[dep].push_back(m);
  left_bounds[curr] = m++;
  //binary lift
  lift[curr][0] = prev;
  for(int i = 1; i < LOG; i++){
    lift[curr][i] = lift[lift[curr][i - 1]][i - 1];
  }
  for(int i : tree[curr]){
    if(i != prev){
      dfs(i, curr, dep + 1);
    }
  }
  right_bounds[curr] = m;
}
int main(){
  //probably a binary lifting problem
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  //build tree
  for(int i = 1; i <= n; i++){
    cin >> r;
    tree[r].push_back(i);
    tree[i].push_back(r);
  }
  dfs(0, 0);
  cin >> m;
  //queries 
  while(m--){
    cin >> v >> p;
    d = depth[v];
    //find the pth ancestor of v
    for(int i = LOG - 1; i >= 0; i--){
      if(p & (1 << i)){
        v = lift[v][i];
      }
    }
    if(v == 0){
      cout << 0 << ' ';
      continue;
    }
    //answer depth queries
    int l = left_bounds[v], r = right_bounds[v];
    cout << lower_bound(node_depth[d].begin(), node_depth[d].end(), r) - lower_bound(node_depth[d].begin(), node_depth[d].end(), l) - 1 << ' ';
  }
}
/*
idea: binary lift to find the cousins
now we need to answer depth queries for the node 
*/