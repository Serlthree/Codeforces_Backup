#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, m, mem[N], b[N], c[N], j, k, x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        j = k = 0;
        //only 1 and 2 convenience points
        for(int i = 0; i < n; i++){
            cin >> mem[i];
        }
        //if conv = 1, store in b, else store in c
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x == 1){
                b[j++] = mem[i];
            }
            else{
                c[k++] = mem[i];
            }
        }
        //sort b and c
        sort(b, b + j);
        sort(c, c + k);
        int j1 = j - 1, k1 = k - 1, m1 = m;
        //odd-even strategy, if odd, take 1 from b, else take 2 (b[j-1] + b[j-2]) or c[k-1]
        //calculate taking an even number of convenience points
        int ans = 0;
        while(m1 > 0){
            if(j1 < 1 && k1 < 0){
                ans = -1;
                break;
            }
            else if(j1 < 1){
                m1 -= c[k1--];
            }
            else if(k1 < 0){
                m1 -= (b[j1--] + b[j1--]); 
            }
            else{
                if(b[j1] + b[j1 - 1] > c[k1]){
                    m1 -= (b[j1--] + b[j1--]);
                }
                else{
                    m1 -= c[k1--];
                }
            }
            ans += 2;
        }
        //calculate taking an odd number of convenience points
        int ans1 = 1;
        j1 = j - 1, k1 = k - 1, m1 = m;
        if(j1 == -1){
            ans1 = -1;
        }
        else{
            int j2 = j1 - 1;
            while(m1 > b[j1]){
                if(j2 < 1 && k1 < 0){
                    ans1 = -1;
                    break;
                }
                else if(j2 < 1){
                    m1 -= c[k1--];
                }
                else if(k1 < 0){
                    m1 -= (b[j2--] + b[j2--]); 
                }
                else{
                    if(b[j2] + b[j2 - 1] > c[k1]){
                        m1 -= (b[j2--] + b[j2--]);
                    }
                    else{
                        m1 -= c[k1--];
                    }
                }
                ans1 += 2;
            }
        }
        if(ans == -1 && ans1 == -1){
            cout << -1 << "\n";
        }
        else if(ans == -1){
            cout << ans1 << "\n";
        }
        else if(ans1 == -1){
            cout << ans << "\n";
        }
        else{
            cout << min(ans, ans1) << "\n";
        }
    }
}