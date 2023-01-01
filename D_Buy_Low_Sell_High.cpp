#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

priority_queue<int,vector<int>,greater<int>> pq;
ll ans;
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    pq.push(x);
    if(x > pq.top()){
      ans += x - pq.top();
      pq.pop();
      pq.push(x);
      //cout << ans << " ";
    }
  }
  cout << ans;
}