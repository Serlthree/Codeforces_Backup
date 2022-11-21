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
const int STMAX = 1 << 18;
//Direction helpers
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
#define checkBounds(x,n) x >= 0 && x < n
using namespace std;

int n, m, y, x;
ll chmax[STMAX], tree[STMAX];
void mod_update(int l, int r, int v, int ss = 1, int se = n, int node = 1){
  if(r < ss || se < l || chmax[node] < v) return; //out of bounds or mod > max
  else if(ss == se){
    tree[node] %= v;
    chmax[node] = tree[node];
  }
  else{
    int mid = (ss+se)/2;
    mod_update(l, r, v, ss, mid, 2*node);
    mod_update(l, r, v, mid+1, se, 2*node+1);
    tree[node] = tree[2*node] + tree[2*node+1];
    chmax[node] = max(chmax[2*node], chmax[2*node+1]);
  }
}
void set_update(int i, ll v, int ss = 1, int se = n, int node = 1){
  if(ss == se){
    chmax[node] = tree[node] = v;
    return;
  }
  int mid = (ss + se) / 2;
  if(i <= mid) set_update(i, v, ss, mid, 2 * node);
  else set_update(i, v, mid + 1, se, 2 * node + 1);
  tree[node] = tree[2*node] + tree[2*node + 1];
  chmax[node] = max(chmax[2*node], chmax[2*node + 1]);
}
ll query(int l, int r, int ss = 1, int se = n, int node = 1){
  if(r < ss || se < l) return 0; //out of bounds
  else if(l <= ss && se <= r) return tree[node]; //completely inbounds
  int mid = (ss + se) / 2;
  return query(l, r, ss, mid, 2 * node) + query(l, r, mid + 1, se, 2 * node + 1);
}
int main(){
  fastIO;
  cin >> n >> m;
  //all we need to do is keep track of max of a certain range, so we build two segtrees
  FORO(i,n){
    cin >> y;
    //build will be same as a point update
    set_update(i,y);
  }
  while(m--){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1){
      cout << query(a,b) << "\n";
      //query
    }
    else if(t == 2){
      //modulo update
      int c;
      cin >> c;
      mod_update(a,b,c);
    }
    else{
      //set update
      set_update(a,b);
    }
  }
  //printArr(tree, 2*n);
  //printArr(chmax, 2*n);
}
/*
note that modulo only halves the array or does nothing
so all we need to do is keep track of the chmax (max value over a range)
so eventually it'll be a O(nlog(a)log(n)) solution a=max
with operation 3 total "entropy" gets added by qlog(a) operations
therefore time complexity is just O(n+q(log(a)(log(N))))
*/