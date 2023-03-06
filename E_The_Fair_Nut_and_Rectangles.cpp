#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6 + 5;
ll convex_q[MAX], dp[MAX];
struct R{
  ll x, y, a;
  bool operator < (R b){
    //by extension sorts by greatest y
    return x < b.x;
  }
} r[MAX];
double slope(int i, int j){
  return (double)(dp[j] - dp[i]) / (double)(r[j].x - r[i].x);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, lef = 0, rig = 0;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> r[i].x >> r[i].y >> r[i].a;
  }
  sort(r + 1, r + n + 1);
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    //note that y decreases
    while(lef < rig && slope(convex_q[lef], convex_q[lef + 1]) > r[i].y) lef++;
    dp[i] = dp[convex_q[lef]] + (r[i].x - r[convex_q[lef]].x) * r[i].y - r[i].a;
    ans = max(ans, dp[i]);
    //removes all points that are not needed
    while(lef < rig && slope(convex_q[rig - 1], convex_q[rig]) < slope(convex_q[rig], i)) rig--;
    convex_q[++rig] = i;
  }
  cout << ans;
}
/*
Uses convex hull trick

dp[i] = x[i] * y[i] - a[i] + max(dp[j] - x[j] * y[i]) for all j < i
x[i], y[i], a[i] are all fixed so therefore we can just maximize dp[j] - x[j] * y[i]

Compare the slopes dp[j] - x[j] * y[i] and dp[j+1] - x[j+1] * y[i]
dp[j] - x[j] * y[i] < dp[j+1] - x[j+1] * y[i] in order to progress
(dp[j] - dp[j+1]) / (x[j] - x[j+1]) < y[i] for j + 1 to be optimal

For insertion we need to keep decreasing slopes

*/