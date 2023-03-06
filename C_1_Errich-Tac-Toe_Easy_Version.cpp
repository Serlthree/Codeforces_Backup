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

int n;
char a[301][301];
bool check(int i, int j){
  //up, left, right, down
  if(checkBounds(i-2,n) && a[i-2][j] == 'X' && a[i-1][j] == 'X'){
    return true;
  }
  else if (checkBounds(i+2,n) && a[i+1][j] == 'X' && a[i+2][j] == 'X'){
    return true;
  }
  else if(checkBounds(j-2,n) && a[i][j-2] == 'X' && a[i][j-1] == 'X'){
    return true;
  }
  else if(checkBounds(j+2,n) && a[i][j+1] == 'X' && a[i][j+2] == 'X'){
    return true;
  }
  else if(checkBounds(i-1,n) && checkBounds(i+1,n) && a[i-1][j] == 'X' && a[i+1][j] == 'X'){
    return true;
  }
  else if(checkBounds(j-1,n) && checkBounds(j+1,n) && a[i][j-1] == 'X' && a[i][j+1] == 'X'){
    return true;
  }
  else{
    return false;
  }
}
void solve(){
  cin >> n;
  //no 3 in a rows
  F0R(i,n){
    F0R(j,n){
      cin >> a[i][j];
    }
  }
  F0R(k,3){
    int opp = 0;
    int plus = 0;
    F0R(i,n){
      F0R(j,n){
        if((i+j)%3 == k && a[i][j] != '.' && check(i,j)){
          opp++;
        }
        if(a[i][j] == 'X'){
          plus++;
        }
      }
    }
    if(opp <= plus/3){
      F0R(i,n){
        F0R(j,n){
          if((i+j)%3 == k && a[i][j] != '.' && check(i,j)){
            a[i][j] = 'O';
          }
          cout << a[i][j];
        }
        cout << "\n";
      }
      break;
    }
  }
}
int main(){
  fastIO;
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}