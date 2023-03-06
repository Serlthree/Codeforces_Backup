#include <bits/stdc++.h>
using namespace std;
int t, n, x;
vector<vector<int>> tree;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> x;
    tree.resize(n);
    for(int i = 0; i < n; i++){
      tree[i].clear();
    }
    for(int i = 0; i < n - 1; i++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    --x;
    if(tree[x].size() <= 1){
      cout << "Ayush\n";
    }
    else{
      if(n % 2 == 0){
        cout << "Ayush\n";
      }
      else{
        cout << "Ashish\n";
      }
    }
  }
}