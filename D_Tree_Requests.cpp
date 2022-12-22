#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

vector<int> tree[MAXN];
vector<pair<int,int>> queries[MAXN];
char str[MAXN];
int ans[MAXN], c[MAXN];
//really smart dfs
void dfs(int node, int depth){
  // xoring here removes all previous xors
  for(auto query : queries[node]){
    // i.second = index of query, i.first = depth of query
    ans[query.second] ^= c[query.first];
  }
  //this only adds
  c[depth] ^= (1<<(str[node]-'a'));
  for(auto child : tree[node]){
    dfs(child, depth + 1);
  }
  // this is the actual addition of the xor
  for(auto query : queries[node]){
    // so if it's a lower tree previous depths will be xored to 0
    ans[query.second] ^= c[query.first];
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 2; i <= n; i++){
    int p;
    cin >> p;
    // 1 sided tree
    tree[p].push_back(i);
  }
  cin >> str + 1; // 1 indexed (c++ supports array to pointer conversion)
  for(int i = 1; i <= m; i++){
    int v, h;
    cin >> v >> h;
    queries[v].push_back({h, i});
  }
  dfs(1,1);
  for(int i = 1; i <= m; i++){
    int j = ans[i];
    if(j&j-1) cout << "No\n";
    else cout << "Yes\n";
  }
}
//time complexity: O(n+m) (only visits each node once and each query twice)