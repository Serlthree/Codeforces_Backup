#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = 4e5 + 5;
using ll = long long;
int n, x, d[MAX];
ll ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    //copy the array to make it circular
    for(int i = 0; i < n; i++){
        d[n + i] = d[i];
    }
    n *= 2;
    //two pointers
    ll l = 0, curr_score = 0, curr_x = 0, place = 0;
    for(int i = 0; i < n; i++){
        curr_x += d[i];
        curr_score += (d[i] * (d[i] + 1))/2;
        //calculate the score, then remove part of the leftmost side
        if(curr_x > x){
            curr_score += (place * (place + 1))/2; //add the removed part back
            place = curr_x - x; //place is the number of days we need to remove
            while(place >= d[l]){
                //remove the leftmost side
                place -= d[l];
                curr_x -= d[l];
                curr_score -= (d[l] * (d[l] + 1))/2;
                l++;
            }
            curr_score -= (place * (place + 1))/2; //remove the part
        }
        //cout << l << " " << i << " " << place << endl;
        ans = max(ans, curr_score);
    }
    cout << ans << endl;
}
/*
optimal is picking the max value and then picking the next biggest max value
also optimal is picking the end of the month

max value is calculated by 
max(d[i],d[max]): if tied then
max(d[i-1],d[max-1]): if tied then
max(d[i-2],d[max-2]): if tied then etc.

or, we can just store the different max values in an array and test them manually, 
worst case is O(n^2)
use a two pointers?
*/