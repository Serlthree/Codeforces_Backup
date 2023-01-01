#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100000;
ll triang[N];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  //precompute triangle numbers
  for(int i = 1; i < N; i++){
    triang[i] = (ll)i * (i + 1) / 2;
  }
  while(t--){
    int n, k;  
    cin >> n >> k;
    string s;
    //find first position
    int pos = (int)(lower_bound(triang, triang + N, k) - triang);
    int pos2 = (int)(k - triang[pos - 1] - 1);
    //cout << pos << " " << pos2 << endl;
    //fill string with 'a's
    for(int i = 0; i < n; i++){
      s += 'a';
    }
    s[n-pos-1] = 'b';
    s[n-pos2-1] = 'b';
    cout << s << endl;
  }
}