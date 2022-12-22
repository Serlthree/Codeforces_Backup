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

string s;
int main(){
  fastIO;
  cin >> s;
  if(s[0] >= 'a' && s[0] <= 'z'){
    s[0] -= 32;
  }
  cout << s;
}