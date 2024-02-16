#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
bool cave[501][501], vis;
int n, m;
pii dir[4] = {{1,0},{-1,0},{0,1},{0,-1}}, s, e;
bool valid(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m && !cave[x][y];
}
void dfs(int x, int y){
  cave[x][y] = true;
  if(x == e.first && y == e.second){
    vis = true;
  }
  for(int i = 0; i < 4; i++){
    int nx = x + dir[i].first, ny = y + dir[i].second;
    if(valid(nx,ny) || (nx == e.first && ny == e.second)){
      dfs(nx,ny);
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      if(c == 'X'){
        cave[i][j] = true;
      }
    }
  }
  cin >> s.first >> s.second >> e.first >> e.second;
  s.first--, s.second--, e.first--, e.second--;
  //Note that the path needs to hit the end point twice (if ice is not cracked)
  //so we can just do a bfs and check if the end point is visited 
  //we can just check if the end has two uncracked ice
  int cnt = 0;
  for(int i = 0; i < 4; i++){
    int x = e.first + dir[i].first, y = e.second + dir[i].second;
    if(valid(x,y) && !cave[x][y] || (x == s.first && y == s.second)){
      cnt++;
    }
  }
  if((cnt < 2 && !cave[e.first][e.second]) || (cnt < 1 && s.first == e.first && s.second == e.second)){
    //cout << cnt << endl;
    cout << "NO" << endl;
    return 0;
  }
  dfs(s.first,s.second);
  if(cave[e.first][e.second] && vis){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}