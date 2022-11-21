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

const int MAX = 1e6 + 1;
int pre[MAX], x;
string s;
int main(){
  fastIO;
  cin >> s;
  int n = s.length();
  //KMP prefix function
  //gives the maximum prefix that is also a suffix at every point
  FOR(i,1,n){
    int j = pre[i-1]; 
    while(j>0&&s[i]!=s[j]){ 
      j = pre[j-1]; //jumps to pre[j-1] to skip duplicates beforehand
    }
    /*if(s[i]!=s[j]){
      j = 0;
    }*/
    if(s[i]==s[j]){ 
      j++; //increases the length if strings are the same
    }
    pre[i] = j;
  }
  FOR(i,1,n-1){
    //works by noting only if at the middle there's the same string as the end
    //or there's an intersection
    //see qwertyqwertyqwerty -> end would produce 12 but we really want the
    //middle string (6)
    if(pre[i]==pre[n-1]||pre[i]==pre[pre[n-1]-1]) x = max(x,pre[i]); 
  }
  //if(x == 0) cout << "Just a legend";
  //else cout << s.substr(0,x);
  printArr(pre,n);
}