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
const int MAX = 2e5+5;
//Direction helpers
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
#define checkBounds(x,n) x >= 0 && x < n
using namespace std;

ll n, a[MAX];
void solve(){
  cin >> n;
  memset(a,0,sizeof(a));
  ll ans = 0, mx = -INF;
  F0R(i,n){
    //always pick last positive and first negative
    cin >> a[i];
  }
  F0R(i,n){
    mx = max(mx,a[i]);
    if(a[i] > 0 && a[i+1] <= 0 || a[i] < 0 && a[i+1] >= 0){
      ans += mx;
      mx = -INF;
    }
    //cout << mx << "\n";
  }
  cout << ans << "\n";
}
int main(){
  fastIO;
  int t; 
  cin >> t;
  while(t--){
    solve();
  }  
}