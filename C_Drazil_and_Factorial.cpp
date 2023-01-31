#include <bits/stdc++.h>
using namespace std;
int n, a[10];
char digit;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> digit;
    a[digit - '0']++;
  }  
  //convert 4
  a[2] += 2*a[4];
  a[3] += a[4];
  a[4] = 0;
  //convert 6
  a[3] += a[6];
  a[5] += a[6];
  a[6] = 0;
  //convert 8
  a[2] += 3*a[8];
  a[7] += a[8];
  a[8] = 0;
  //convert 9
  a[3] += 2*a[9];
  a[2] += a[9];
  a[7] += a[9];
  a[9] = 0;
  for(int i = 9; i >= 2; i--){
    for(int j = 0; j < a[i]; j++){
      cout << i;
    }
  }
}