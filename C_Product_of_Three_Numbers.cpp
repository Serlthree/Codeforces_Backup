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

int t, n, ans[3];
int main(){
  //t*sqrt(n) algorithm
  cin >> t;
  F0R(i,t){
    cin >> n;
    int j = 2;
    int k = 0;
    while(j <= sqrt(n) + 1 && k < 2){
      if(n%j == 0){
        n /= j;
        ans[k++] = j;
      }
      j++;
    }
    if(k == 2 && n > ans[1]){
      cout << "YES\n";
      cout << ans[0] << " " << ans[1] << " " << n << "\n"; 
    }
    else{
      cout << "NO\n";
    }
  }
}
