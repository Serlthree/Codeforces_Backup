#include <bits/stdc++.h>
using namespace std;

string s, t;
int start, _end, unknown;
//nCr
double nCr(int n, int r){
  double ans = 1;
  for(int i = 1; i <= r; i++){
    ans *= (n - i + 1);
    ans /= i;
  }
  return ans;
}
int main(){
  cin >> s >> t;
  cout << setiosflags(ios::fixed) << setprecision(12);
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '+') start++;
    else start--;
    if(t[i] == '+') _end++;
    else if(t[i] == '-') _end--;
    else unknown++;
  }
  if(start == _end && unknown == 0) cout << 1.0 << endl;
  else if(unknown == 0) cout << 0.0 << endl;
  else{
    int diff = abs(start - _end);
    if(diff > unknown) cout << 0.0 << endl;
    else{
      if(diff % 2 != unknown % 2) cout << 0.0 << endl;
      else{
        int x = (unknown + diff) / 2;
        cout << nCr(unknown, x) / pow(2, unknown) << endl;
      }
    }
  }
}