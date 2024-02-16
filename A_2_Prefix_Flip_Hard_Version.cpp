#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
vector<int> ans1, ans2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        ans1.clear();
        ans2.clear();
        cin >> n;
        cin >> a >> b;
        for(int i = 0; i < n - 1; i++){
            //make a all 1's
            //every time a[i] != a[i+1], flip
            if(a[i] != a[i+1]){
                ans1.push_back(i + 1);
            }
        }
        if(a[n - 1] == '0'){
            ans1.push_back(n);
        }
        //make b all 1's
        for(int i = 0; i < n - 1; i++){
            if(b[i] != b[i+1]){
                ans2.push_back(i + 1);
            }
        }
        if(b[n - 1] == '0'){
            ans2.push_back(n);
        }
        reverse(ans2.begin(), ans2.end());
        cout << ans1.size() + ans2.size() << " ";
        for(int i = 0; i < ans1.size(); i++){
            cout << ans1[i] << " ";
        }
        for(int i = 0; i < ans2.size(); i++){
            cout << ans2[i] << " ";
        }
        cout << "\n";
    }
}
/*
5
01011
11100
flip 1
11011
flip 2
00011
flip 3
11111
flip 5
00000
flip 3
11100
*/