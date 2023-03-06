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

const int MAX = 505;
//using range dp technique
int n,c[MAX], dp[MAX][MAX]; 
int main(){
  fastIO;
  cin >> n;
  //convert this to a palindrome (return 1)
  FORO(i,n){
    cin >> c[i];
  }
  FORB(i,n,1){
    FOR(j,i,n+1){
      dp[i][j] = dp[i][j-1] + 1; //without palindrome checking
      FOR(k,i,j){
        //palindrome checking
        if(c[k] == c[j]){
          //dp[k][j] is not computed yet
          dp[i][j] = min(dp[i][j],dp[i][k-1]+max(1,dp[k+1][j-1])); 
        }
      }
    }
  }
  /*F0R(i,n+1){
    printArr(dp[i],n+1);
    cout << "\n"; 
  }*/
  cout <<dp[1][n];
}