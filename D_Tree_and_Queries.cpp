#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;

int colors[MAX], ans[MAX];
vector<int> adj[MAX];
vector<pair<int,int>> queries[MAX];
map<int,int> cnt[MAX], freq[MAX];
//dfs with union find
inline void dfs(int node, int prev){
  cnt[node][colors[node]] = 1;
  freq[node][1]++;
  for(int child : adj[node]){
    if(child != prev){
      dfs(child, node);
      if(cnt[node].size() < cnt[child].size()){
        swap(cnt[node], cnt[child]);
        swap(freq[node], freq[child]);
      }
      for(auto p : cnt[child]){
        int c = p.first, f = p.second;
        //complex counting of frequencies
        if(cnt[node].count(c)){
          //update existing color
          freq[node][cnt[node][c]]--;
          if(freq[node][cnt[node][c]] == 0){
            freq[node].erase(cnt[node][c]);
          }
          cnt[node][c] += f;
          freq[node][cnt[node][c]]++;
        }
        else{
          //add new color
          cnt[node][c] = f;
          freq[node][f]++;
        }
      }
    }
  }
  //answer queries
  for(auto p : freq[node]){
    for(auto q : queries[node]){
      if(p.first >= q.first){
        //note q.second = index, p.second = frequency of frequencies
        ans[q.second] += p.second;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> colors[i];
  }
  for(int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i < m; i++){
    int v, c;
    cin >> v >> c;
    queries[v].push_back({c,i+1});
  }
  dfs(1,0);
  for(int i = 1; i <= m; i++){
    cout << ans[i] << "\n";
  }
}