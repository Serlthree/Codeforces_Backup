#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
int t, c, d, x, s[N], rel[N];
//sieve of eratosthenes
void build(){
  for(int i = 2; i * i < N; i++){
    if(!s[i]){
      for(int j = i*i; j < N; j += i){
        s[j] = i;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  build();
  cin >> t;
  //find number of relatively prime pairs
  for(int i = 1; i < N; i++){
    if(i == 1){
      rel[i] = 1;
    }
    else if (!s[i]){
      rel[i] = 2;
    }
    else{
      int p = s[i];
      int q = i / p;
      if(q % p == 0){
        rel[i] = rel[q];
      }
      else{
        rel[i] = rel[q] * 2;
      }
    }
  }
  //solve queries
  while(t--){
    cin >> c >> d >> x;
    int ans = 0;
    for(int i = 1; i * i <= x; i++){
      if(x % i == 0){
        if((i+d)%c == 0){
          ans += rel[(i+d)/c];
        }
        if(i*i != x && (x/i+d)%c == 0){
          ans += rel[(x/i+d)/c];
        }
      }
    }
    cout << ans << "\n";
  }
}