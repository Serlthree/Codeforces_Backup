#include <iostream>
using namespace std;
int t, n, x, o, e, a;
int main(){
  cin >> t;
  while(t--){
    cin >> n >> x;
    o = 0; e = 0;
    for(int i = 0; i < n; i++){
      cin >> a;
      if(a & 1) o++;
      else e++;
    }
    o--;
    if(o == -1) cout << "No\n";
    else if(e >= 1 && (o/2)*2 + e >= (x-1)) cout << "Yes\n";
    else if (e == 0 && (x-1)%2 == 0 && (o/2)*2 >= (x-1)) cout << "Yes\n";
    else cout << "No\n";
  }
}
