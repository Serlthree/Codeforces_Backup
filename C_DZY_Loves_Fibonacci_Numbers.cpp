#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 9;
const int N = 3e5 + 10;
ll fib[N], t3[N], t1[N], t2[N];
int n, m;
//binary indexed tree update
void add (ll t[], int pos, ll val){
  for(; pos <= n; pos += pos & -pos){ //uses two's complement to get the last set bit and add it to pos
    t[pos] = (t[pos] + val) % MOD;
  }
}
//binary indexed tree query
ll sum(ll t[], int pos){
  ll ans = 0;
  for(; pos > 0; pos -= pos & -pos){
    ans = (ans + t[pos]) % MOD;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  fib[0] = fib[1] = 1;
  for(int i = 2; i < N; i++){
    fib[i] = (fib[i-1] + fib[i-2]) % MOD;
  }
  cin >> n >> m;
  for(int i = 1, x; i <= n; i++){
    cin >> x;
    add(t3, i, x);
  }
  //verify that the tree is correct
  /*for(int i = 1; i <= n; i++){
    cout << t3[i] << " ";
  }*/
  while(m--){
    int t, l, r;
    cin >> t >> l >> r;
    //type = 1, update
    if(t == 1){
      int sign = (l & 1) ? -1 : 1;
      add(t1, l, sign * fib[l]);
      add(t2, l, sign * (-1) * fib[l+1]);
      add(t3, l, -1);
      //adds the opposite of the previous value
      add(t1, r, fib[l] * sign * (-1));
      add(t2, r, fib[l+1] * sign);
      add(t3, r, fib[r-l+2]);
    }
    //type = 2, query
    else{
      l--;
      //sum from 1 to l
      ll sum1 = sum(t1, l) * fib[l+4] + sum(t2, l) * fib[l+3] + sum(t3, l);
      //cout << sum(t1, r) << " " << sum(t2, r) << " " << sum(t3, r) << "\n";
      //sum from 1 to r 
      ll sum2 = sum(t1, r) * fib[r+4] + sum(t2, r) * fib[r+3] + sum(t3, r);
      cout << ((sum2 - sum1)%MOD + MOD) % MOD << "\n";
    }
  }
}
/*
Via proof by induction, 
f(n) - 1 = f(0) + f(1) + ... + f(n-2) -> sequences completely within the range we're looking for
(Obviously can stack with multiple updates)

Next intuition -> sequences that are cut short by the range we're looking for
via algebra
  fib[l] * fib[r+4] - fib[l+1] * fib[r+3] 
= fib[l] * fib[r+2] - fib[l-1] * fib[r+3]
= fib[l-2] * fib[r+2] - fib[l-1] fib[r+1] 
After several iterations, we get

If l is odd,
= fib[1] * fib[r-l+5] - fib[2] * fib[r-l+4]
= fib[-1] * fib[r-l+3] - fib[0] * fib[r-l+2]
= -fib[r-l+2]

If l is even,
= fib[0] * fib[r-l+4] - fib[1] * fib[r-l+3]
= fib[r-l+2]

So we can use a BIT (fenwick) to store the left values and then use the right value query to get the answer
This also would work with update stacking
*/