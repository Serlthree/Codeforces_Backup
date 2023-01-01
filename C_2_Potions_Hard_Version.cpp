#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N], pre[N];
queue<int> v;
priority_queue<int> pq;
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pre[i] += pre[i-1] + a[i];
    if(pre[i] < 0){
      v.push(i);
    }
  }
  //second traversal
  int ans = n;
  int _add = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] < 0){
      pq.push(-a[i]);
    }
    if(!v.empty() && v.front() == i){
      int x = pre[v.front()] + _add;
      v.pop();
      while(!pq.empty() && x < 0){
        x += pq.top();
        _add += pq.top();
        pq.pop();
        ans--;
      }
      //cout << _add;
    }
  }
  cout << ans;
}

/*
obviously always take the heal potions
prefix sum sol
check for negatives in prefix 
and remove the biggest negative
*/