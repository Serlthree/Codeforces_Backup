#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
int n, mx;
string s, ans;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  while(n--){
    cin >> s;
    m[s]++;
    if(m[s] > mx){
      mx = m[s];
      ans = s;
    }
  }
  cout << ans;
}