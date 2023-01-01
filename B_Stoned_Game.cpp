#include <bits/stdc++.h>
using namespace std;

int t, n, a[101];
int main(){
  cin >> t;
  while(t--){
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    if(a[n-1] > sum/2){
      cout << "T" << '\n';
    }
    else if(sum % 2 == 0){
      cout << "HL" << '\n';
    }
    else{
      cout << "T" << '\n';
    }
  }
}