#include <bits/stdc++.h>
using namespace std;

int four[] = {1,3,0,2}, five[] = {0,3,1,4,2}, six[] = {0,4,1,3,5,2}, seven[] = {0,4,6,2,5,3,1};
void solve(){
  int n;
  cin >> n;
  //loop in 4's 
  if(n <= 3){
    cout << -1 << '\n';
  }
  else{
    int cnt = 1;
    while(n >= 4){
      if(n == 7){
        for(int i = 0; i < 7; i++){
          cout << cnt + seven[i] << ' ';
        }
        cout << '\n';
        return;
      }
      else if (n == 6){
        for(int i = 0; i < 6; i++){
          cout << cnt + six[i] << ' ';
        }
        cout << '\n';
        return;
      }
      else if (n == 5){
        for(int i = 0; i < 5; i++){
          cout << cnt + five[i] << ' ';
        }
        cout << '\n';
        return;
      }
      else{
        for(int i = 0; i < 4; i++){
          cout << cnt + four[i] << ' ';
        }
        cnt += 4;
        n -= 4;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}