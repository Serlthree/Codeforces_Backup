#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
int T, n, a[N], b[N], c[N], ans, mn;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        ans = 0;
        mn = 1e18;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        //c[i] = a[i] - b[i - 1];, i = 0 goes to n - 1
        for(int i = 0; i < n; i++){
            i == 0 ? c[i] = max(0LL,a[i] - b[n - 1]) : c[i] = max(0LL,a[i] - b[i - 1]);
            ans += c[i];
            mn = min(mn, a[i] - c[i]);
        }
        //debug c[i]
        //for(int i = 0; i < n; i++) cout << c[i] << " ";
        cout << ans + mn << "\n";
    }
}
/*
insight: always take consecutives
7 15 4
2 14 0
5 3 0


*/