#include <bits/stdc++.h>
using namespace std;

vector<int> a[26];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  for(int i = 0; i < n; i++){
    //index of characters stored in 2d array
    a[s[i] - 'a'].push_back(i);
  }
  int cnt = 0;
  while(q--){
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    //brute force 26*n*q worst case
    for(int x = 26 - 26 * k, c = l; c < r; x += k*2-1){
      for(int y = lower_bound(a[x].begin(), a[x].end(), l) - a[x].begin(); y < a[x].size() && a[x][y] < r; y++){
        //changes index of character to sort
        a[x][y] = c++; 
        cnt++;
      }
    }
  }
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < a[i].size(); j++){
      s[a[i][j]] = i + 'a';
    }
  }
  //cout << s;
  cout << cnt;
}