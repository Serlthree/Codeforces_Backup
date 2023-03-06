#include<bits/stdc++.h>
using namespace std;
int t, n, ans, res;
char s[51];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        ans = 0, res = 0;
        cin >> n >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') ans++;
            else ans--;
            if(ans < 0){
                res++;
                ans = 0;
            } 
        }
        cout << res << "\n";
    }
}