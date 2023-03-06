#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
  cin >> n;
  if(n > 0){
    cout << n << endl;
  }
  else if(n%10 < n/10%10){
    cout << n/10 << endl;
  }
  else{
    cout << n/100*10 + n%10 << endl;
  }
}