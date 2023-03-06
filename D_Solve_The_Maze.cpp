#include <iostream>
using namespace std;

int n, m;
char a[51][51];
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
bool checkBounds(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m;
}
bool dfs(int x, int y){
  if(x == n-1 && y == m-1) return true;
  if(a[x][y] == '#' || a[x][y] == 'B') return false;
  bool ret = false;
  a[x][y] = '#';
  //cout << x << ' ' << y << '\n';
  for(int i = 0; i < 4; i++){
    int nx = x + rdir[i];
    int ny = y + cdir[i];
    if(checkBounds(nx,ny) && (a[nx][ny] == '.' || a[nx][ny] == 'G')){
      ret |= dfs(nx,ny);
    }
  }
  //a[x][y] = '.';
  return ret;
}
void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      if(i == n - 1 && j == m - 1 && a[i][j] == 'B'){
        cout << "No" << '\n';
        return;
      }
    }
  }
  // trap all bad guys
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 'B'){
        for(int k = 0; k < 4; k++){
          int x = i + rdir[k];
          int y = j + cdir[k];
          if(checkBounds(x,y) && a[x][y] == '.'){
            a[x][y] = '#';
          }
        }
      }
      //if adjacent to bad guy, then it is not a valid path
      else if(a[i][j] == 'G'){
        for(int k = 0; k < 4; k++){
          int x = i + rdir[k];
          int y = j + cdir[k];
          if(checkBounds(x,y) && a[x][y] == 'B'){
            cout << "No" << '\n';
            return;
          }
        }
      }
    }
  }
  // checks if all good guys have a path
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 'G'){
        bool ret = false;
        ret = dfs(i,j);
        if(!ret){
          cout << "No" << '\n';
          return;
        }
      }
    }
  }
  cout << "Yes" << '\n';
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}