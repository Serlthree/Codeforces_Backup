#include <bits/stdc++.h>
#define contains(i) (m.count(i) > 0)
using namespace std;
int n, k, a[100001];
void solve()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] == k) a[i] = 0;
    else if(a[i] < k) a[i] = -1;
    else a[i] = 1;
  }
  if(n == 1 && a[0] == 0){
    cout << "yes\n";
    return;
  }
  bool flag1 = false;
  bool flag2 = false;
  //HUGE NOTE: you only need 3 consecutive numbers 
  //and you only need to check if there are two numbers greater
  for(int i = 0; i < n; i++){
    if(a[i] == 0){
      flag1 = true;
    }
    if(i < n -1 && a[i] >= 0 && a[i+1] >= 0){
      flag2 = true;
    }
    if(i < n-2 && a[i] >= 0 && a[i+2] >= 0){
      flag2 = true;
    }
  }
  if(flag1 && flag2) cout << "yes\n";
  else cout << "no\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  //merging higher is also good
  //we only need two consecutive numbers
}