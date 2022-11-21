#include <bits/stdc++.h>
#define F0R(i,n) for(int i = 0; i < n; i++)
#define F0RB(i,n) for(int i = n; i >= 0; i--)
#define FOR(i,n,k) for(int i = n; i < k; i++)
#define FORO(i,n) for(int i = 1; i <= n; i++)
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
}
//modulos
const int modulo = 1e8;
//infinity
const int INF = 1e9;
const long long LINF = INT64_MAX;
//Direction helpers
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
#define checkBounds(x,n) x >= 0 && x < n
using namespace std;

const int MAX = 2e5 + 1;
ll n, k, g[MAX], sz[MAX],u,v;
vector<int> tree[MAX];
void dfs(int cur, int pre, int depth){
 //cout << cur << endl;
  for(int nex : tree[cur]){
    if(nex != pre){
      dfs(nex,cur,depth+1);
      g[cur] -= sz[nex];
      sz[cur] += sz[nex];
    }
  }
  g[cur] += depth;
}
int main(){
  //greedy algorithm
  fastIO;
  cin >> n >> k;
  F0R(i,n-1){
    cin >> u >> v;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  F0R(i,n){
    sz[i+1] = 1;
  }
  //choose industry cities based on highest depth - sz of subtrees
  dfs(1,0,0);
  //printArr(g,n+1);
  sort(g+1,g+n+1);
  ll ans = 0;
  F0R(i,k){
    ans += g[n-i];
  }
  cout << ans;
}