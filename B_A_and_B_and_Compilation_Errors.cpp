#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> s1, s2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    s1[x]++;
  }
  for(int i = 0; i < n-1; i++){
    int x;
    cin >> x;
    s1[x]--;
    if(s1[x] == 0)
      s1.erase(x);
    s2[x]++;
  }
  cout << s1.begin()->first << endl;
  for(int i = 0; i < n-2; i++){
    int x;
    cin >> x;
    s2[x]--;
    if(s2[x] == 0)
      s2.erase(x);
  }
  cout << s2.begin()->first << endl;
}