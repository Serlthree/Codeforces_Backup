#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
//segment tree just stores indexes of nodes being added
int tree[N][2], cind, n, q, s;
//actual weighted graph
vector<pair<int, int>> adj[N];
//dijkstras helpers
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
ll dist[N];
//debug tools
void printAdjList(){
  for(int i = 1; i <= cind; i++){
    cout << i << ": ";
    for(auto e : adj[i]){
      cout << e.first << " ";
    }
    cout << endl;
  }
}
//type 1 operations: node can go to node
//type 2 operations: node can go to range of nodes
//type 3 operations: range of nodes can go to node
void add(int u, int v, ll w){
  adj[u].push_back({v, w});
}
void build(int ind, int type, int l = 1, int r = n){
  tree[ind][type] = ++cind;
  if(l == r){
    if(type == 0){
      add(tree[ind][type], l, 0);
    }
    else{
      add(l, tree[ind][type], 0);
    }
  }
  else{
    int mid = (l + r) / 2;
    build(2*ind, type, l, mid);
    build(2*ind+1, type, mid + 1, r);
    //support type 2 operations
    if(type == 0){
      add(tree[ind][type], tree[2*ind][type], 0);
      add(tree[ind][type], tree[2*ind + 1][type], 0);
    }
    //support type 3 operations
    else{
      add(tree[2*ind][type], tree[ind][type], 0);
      add(tree[2*ind + 1][type], tree[ind][type], 0);
    }
  }
}
void modify(int ind, int cl, int cr, int type, int v, int w, int l = 1, int r = n){
  if(cl > r || cr < l){
    return;
  }
  if(cl <= l && cr >= r){
    if(type == 0){
      add(v, tree[ind][type], w);
    }
    else{
      add(tree[ind][type], v, w);
    }
  }
  else{
    int mid = (l + r) / 2;
    modify(2*ind, cl, cr, type, v, w, l, mid);
    modify(2*ind+1, cl, cr, type, v, w, mid + 1, r);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q >> s;
  cind = n;
  //build
  build(1, 0);
  build(1, 1);
  //add edges
  for(int i = 0; i < q; i++){
    int t;
    cin >> t;
    if(t == 1){
      int v, u, w;
      cin >> v >> u >> w;
      add(v, u, w);
    }
    else{
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      modify(1, l, r, t-2, v, w);
    }
  }
  //printAdjList();
  //dijkstra with possible cycles
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  for(int i = 1; i <= n; i++){
    pq.push({dist[i], i});
  }
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    for(auto e : adj[u]){
      int v = e.first;
      ll w = e.second;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(dist[i] == 0x3f3f3f3f3f3f3f3f){
      cout << -1 << " ";
    }
    else{
      cout << dist[i] << " ";
    }
  }
}