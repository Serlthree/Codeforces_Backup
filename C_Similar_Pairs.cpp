#include <bits/stdc++.h>
using namespace std;
int t, n, a[102], x, numEven;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        numEven = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++){
            cin >> x;
            a[x]++;
            if(x % 2 == 0) numEven++;
        }
        if(numEven % 2 == 0){
            cout << "YES" << "\n";
        } else {
            bool flag = false;
            for(int i = 1; i <= 100; i++){
                if(a[i] > 0 && a[i + 1] > 0){
                    flag = true;
                    break;
                }
            }
            if(flag) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}