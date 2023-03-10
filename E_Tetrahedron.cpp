#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int n, r1 = 1, r2 = 0, r3 = 0, r4 = 0;
signed main(){
    cin >> n;
    while(n--){
        r3 = (3 * r2) % MOD;
        r4 = ((2 * r2) % MOD + r1) % MOD;
        r2 = r4;
        r1 = r3;
    }
    cout << r1;
}
/*
1 0 0 0
0 1 1 1 (1)
3 2 2 2 (2)
6 7 7 7 (3)
21

Every iteration
R2 = R3 = R4
R1 = 3R2
R2 = 2R2 + R1
*/