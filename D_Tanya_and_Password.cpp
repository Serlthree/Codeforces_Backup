#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
const int CHAR = 76;
const int CHARS = CHAR*CHAR + 5;
int n, x, y;
int deg[CHARS];
vector<int> adj[CHARS];
string ans, s;
void dfs(int u){
  while(adj[u].size() > 0){
    //visit the last edge in the adjacency list
    int v = adj[u].back();
    //remove edge when we visit it
    adj[u].pop_back();
    dfs(v);
  }
  //add the first char of the edge to the answer (note: we are going backwards)
  ans += (char)(u % CHAR + 48);
}
int main(){
  //eulerian path
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    //store 2 chars in 1 int
    x = (s[0] - 48) * CHAR + (s[1] - 48);
    y = (s[1] - 48) * CHAR + (s[2] - 48);
    deg[x]++; deg[y]--;
    adj[x].push_back(y);
  }
  //check if eulerian path exists (directed)
  int st = 0, cnt = 0;
  for(int i = 0; i < CHARS; i++){
    if(deg[i] >= 1) st = i, cnt++;
    //for every deg[i] >= 1, there must be a deg[i] <= -1 because we always are at a net 0
  }
  if(cnt > 1 || deg[st] > 1) {
    cout << "NO";
    return 0;
  }
  //find eulerian path
  //initalize start if start can't be found
  if(st == 0) for(int i = 0; i < CHARS; i++) if(adj[i].size() > 0) st = i;
  dfs(st);
  //add the starting char to the answer
  ans += (char)(st/CHAR + 48);
  //reverse the answer because we are going backwards
  reverse(ans.begin(), ans.end());
  //check if the answer is valid
  if(ans.size() != n + 2) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  cout << ans;
}
/*
ascii values of 
a-z = 97-122
A-Z = 65-90
0-9 = 48-57
122-48+1 = 75
*/