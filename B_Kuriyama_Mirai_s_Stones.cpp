#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], pre[N], sorted_pre[N], m, t, l, r;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        sorted_pre[i] = sorted_pre[i - 1] + a[i];
    }
    cin >> m;
    while(m--){
        cin >> t >> l >> r;
        if(t == 1){
            cout << pre[r] - pre[l - 1] << "\n";
        } else {
            cout << sorted_pre[r] - sorted_pre[l - 1] << "\n";
        }
    }
}