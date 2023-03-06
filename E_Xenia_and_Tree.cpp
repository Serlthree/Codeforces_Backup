#include <bits/stdc++.h>
//for loops
#define F0R(i,n) for(int i = 0; i < n; i++)
#define F0RB(i,n) for(int i = n; i >= 0; i--)
#define FORB(i,n,k) for(int i = n; i >= k; i--)
#define FOR(i,n,k) for(int i = n; i < k; i++)
#define FORO(i,n) for(int i = 1; i <= n; i++)
//shorthand
#define pii pair<int,int>
#define setprecision(x) cout << setiosflags(ios::fixed) << setprecision(x)
#define pb push_back
#define mp make_pair
#define fastIO std::ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ull = unsigned long long;
//precision error functions
template <typename T>
T frac_ceil(T a, T b){
  return (a+b-1)/b;
}
//Print tools
template <typename T> 
void printArr(T array[], int SIZE)
{
  for(int i = 0; i < SIZE; i++) std::cout << array[i] << " ";
  std::cout<<"\n";
}
//modulos
const int modulo = 1e8;
//infinity
const int INF = 1e9;
const long long LINF = INT64_MAX;
const int MEMINF = 0x3f3f3f3f;
//random useful constants
const int LOG = 19;
const int STMAX = 1 << LOG;
const int MAX = 1e5+5;
//Direction helpers
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
#define checkBounds(x,n) x >= 0 && x < n
using namespace std;
 
int n, m, dist[MAX], depth[MAX], up[MAX][LOG], query[MAX], top, start;
vector<int> tree[MAX];
void dfs(int x, int y){
  dist[x] = dist[y] + 1;
  depth[x] = depth[y] + 1;
  up[x][0] = y; //first ancestor in the path
  for(int i = 1; i < LOG; i++){
    //splits the jump into two jumps of half the distance
    //etc for 8th ancestor it gets the 4th ancestor of the 4th ancestor
    up[x][i] = up[up[x][i-1]][i-1]; 
  }
  for(int i : tree[x]){
    if(i != y) dfs(i,x);
  }
}
//figure out lca
int lca(int x, int y){
  if(depth[x] < depth[y]) swap(x,y);
  F0RB(i,LOG-1){
    if(depth[up[x][i]] >= depth[y]) x = up[x][i]; //sets to be equal depth
  }
  if(x == y) return x;
  F0RB(i,LOG-1){
    if(up[x][i] != up[y][i]){
      x = up[x][i];
      y = up[y][i];
    }
  }
  return up[x][0];
}
int main(){
  fastIO;
  cin >> n >> m;
  F0R(i,n-1){
    int a, b;
    cin >> a >> b;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  dist[0] = -1; //initalizes 1 to 0
  dfs(1,0);
  while(m--){
    int t, v;
    cin >> t >> v;
    if(t == 1){
      query[top++] = v;
      //sqrt decomposition for queries
      //Time complexity sqrt(n) * n (bfs)
      if(top >= 100){ //sqrt of MAX
        F0R(i,top){
          dist[query[i]] = 0;
        }
        while(start != top){ //bfs
          int x = query[start++];
          for(int i : tree[x]){
            if(dist[i] > dist[x] + 1){
              dist[i] = dist[x] + 1;
              query[top++] = i;
            }
          }
        }
        start = top = 0;
      }
    }
    else{
      //uses the fact that you can just manually calculate the distances with lca
      //and that you only store 100 queries at a time
      //Time complexity q * sqrt(n) * log(n);
      int ans = dist[v];
      F0R(i,top){
        ans = min(ans, depth[v] + depth[query[i]] - depth[lca(v,query[i])] * 2);
      }
      cout << ans << '\n';
    }
  }
}