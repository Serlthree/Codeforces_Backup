#include <bits/stdc++.h>
const int MAX = 1e5 + 5;
using namespace std;

template <typename T>
void printArray(T arr[], int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

vector<int> tree[MAX];
int depth[MAX], parent[MAX][20], n, q, sz[MAX];
inline void dfs(int node, int prev, int d){
  sz[node] = 1;
  depth[node] = d;
  parent[node][0] = prev;
  for(int i = 1; i < 20; i++){
    parent[node][i] = parent[parent[node][i - 1]][i - 1];
  }
  for(int i : tree[node]){
    if(i != prev){
      dfs(i, node, d + 1);
      sz[node] += sz[i];
    }
  }
}
inline int lca(int node, int node2){
  if(depth[node] < depth[node2]){
    swap(node, node2);
  }
  //makes sure they're the same depth
  for(int i = 19; i >= 0; i--){
    if(depth[node] - (1 << i) >= depth[node2]){
      node = parent[node][i];
    }
  }
  if(node == node2){
    return node;
  }
  for(int i = 19; i >= 0; i--){
    if(parent[node][i] != parent[node2][i]){
      node = parent[node][i];
      node2 = parent[node2][i];
    }
  }
  return parent[node][0];
}
inline int kthAncestor(int node, int k){
  for(int i = 19; i >= 0; i--){
    if(k & (1 << i)){
      node = parent[node][i];
    }
  }
  return node;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  int m;
  cin >> m;
  //should be a binary lifting solution
  dfs(1, 0, 1);
  //printArray(sz,n+1);
  while(m--){
    int a, b;
    cin >> a >> b;
    int l = lca(a, b);
    //cout << l << endl;
    if(depth[a] == depth[b]){
      //should be size just before lca
      int dep = depth[a] - depth[l]; 
      cout << n - sz[kthAncestor(a,dep-1)] - sz[kthAncestor(b,dep-1)] << '\n';
    }
    else if((depth[a]-depth[b])%2 != 0){
      cout << 0 << '\n';
    }
    else{
      if(depth[a] < depth[b]){
        swap(a, b);
      }
      int d = depth[a] + depth[b] - 2*depth[l];
      d /= 2;
      int node = kthAncestor(a, d);
      cout << sz[node] - sz[kthAncestor(a, d - 1)] << '\n';
    }
  }
}
/*
So it basically is a lca problem
*/