#include <bits/stdc++.h>
using namespace std;
int t;
bool dp[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[2020] = dp[2021] = 1;
    for(int i = 2022; i <= 1000000; i++){
        dp[i] = dp[i-2020] || dp[i-2021];
    }
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n] ? "YES" : "NO") << "\n";
    }
}