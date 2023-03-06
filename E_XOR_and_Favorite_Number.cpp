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
//Direction helpers
const int rdir[4] = {1,0,-1,0};
const int cdir[4] = {0,1,0,-1};
#define checkBounds(x,n) x >= 0 && x < n
using namespace std;

const int MAX = 1e5 + 1;
ll n, m, k, a[MAX], sqrtn, res[MAX];
ll hm[3000005];
struct Query{
  int l, r, ind;
} q[MAX];
bool cmp (Query a, Query b){
  if((a.l-1)/sqrtn < (b.l-1)/sqrtn){
    return true;
  }
  else if((a.l-1)/sqrtn == (b.l-1)/sqrtn && a.r < b.r){
    return true;
  }
  return false;
}
int main(){
  //prefix for xor works
  fastIO;
  cin >> n >> m >> k;
  sqrtn = sqrtl(n);
  FORO(i,n){
    cin >> a[i];
    a[i] ^= a[i-1];
  }
  F0R(i,m){
    cin >> q[i].l >> q[i].r;
    q[i].ind = i;
  }
  //printArr(a,n+1);
  //mo's algorithm (sqrt decomp)
  sort(q,q+m,cmp);
  ll l = 0, r = 0, ans = 0;
  F0R(i,m){
    int L = q[i].l, R = q[i].r;
    while(r < R + 1){
      ans += hm[k^a[r]];
      hm[a[r]]++;
      r++;
    }
    while(r > R + 1){
      r--;
      hm[a[r]]--;
      ans -= hm[k^a[r]];
    }
    while(l < L - 1){
      hm[a[l]]--;
      ans -= hm[k^a[l]];
      l++;
    }
    while(l > L - 1){
      l--;
      ans += hm[k^a[l]];
      hm[a[l]]++;
    }
    res[q[i].ind] = ans;    
    //printArr(hm,1);
    //cout << q[i].l << " " << q[i].r << endl;
  }
  F0R(i,m){
    cout << res[i] << "\n";
  }
}
/*
0 1 0 1 0 1
3 3
*/