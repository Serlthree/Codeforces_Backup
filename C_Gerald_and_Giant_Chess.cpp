#include <bits/stdc++.h>
using namespace std;
//unfortunately can't use unsigned long long
using ull = long long;
using pii = pair<int,int>;
const int N = 2e5 + 10;
const ull mod = 1e9 + 7;
// precompute permutation
ull fact[N];
void precompute()
{
  fact[0] = 1;
  for (int i = 1; i < N; i++)
  {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
// compute modular inverse
ull modInverse(ull a, ull m)
{
  ull m0 = m;
  ull y = 0, x = 1;
  if (m == 1)
    return 0;
  while (a > 1)
  {
    ull q = a / m;
    ull t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0)
    x += m0;
  return x;
}
// compute nCr
ull nCr(ull n, ull r)
{
  if (r > n)
    return 0;
  if (r == 0)
    return 1;
  return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) % mod;
}
// we will figure the above out later ^
int h, w, n;
pii v[N];
ull dp[N];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  precompute();
  cin >> h >> w >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
  }
  sort(v, v + n);
  n++;
  ull ans = nCr(h + w - 2, h - 1);
  for(int i = 0; i < n; i++){
    dp[i] = nCr(v[i].first + v[i].second - 2, v[i].first - 1);
    for(int j = 0; j < i; j++){
      if(v[j].second <= v[i].second){
        ull sub = nCr(v[i].first - v[j].first + v[i].second - v[j].second, v[i].first - v[j].first);
        dp[i] = (dp[i] - sub * dp[j] % mod + mod) % mod;
      }
    }
    //compute remaining paths to the end
    ull rem = nCr(h - v[i].first + w - v[i].second, h - v[i].first);
    ans = (ans - dp[i] * rem % mod + mod) % mod;
  }
  cout << ans << endl;
}