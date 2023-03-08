#include <bits/stdc++.h>
using namespace std;
int t, n, best;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        best = n - 1;
        for(int i = 2; i <= sqrtl(n); i++){
            if(n % i == 0){
                best = min(best, n - (n / i));
            }
        }
        cout << n - best << " " << best << "\n";
    }    
}