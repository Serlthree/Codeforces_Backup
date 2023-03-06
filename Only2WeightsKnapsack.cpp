#include <bits/stdc++.h>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
const double pi = 3.141592653589793238;
const int INF = 1000000000;
const int MEMINF = 0x3f;
 
#define mii map<int,int>
#define ld long double
#define ll long long
#define pb push_back
#define mp make_pair
#define F0R(i,j) for(int i = 0; i < (int)j; i++)
#define FOR(i,j,k) for (int i = j; i < (int)k; i++)
#define FORE(i,j,k) for(int i = j; i <= (int)k; i++)
#define FORN(i, n) for(int i=(n)-1; i>=0; i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<ld,ld>
#define vi vector<int>
#define se second
#define fi first
#define si(x) scanf("%d",&x)
#define sf scanf
#define pf printf
#define quick ios::sync_with_stdio(false)
#define precision(x) cout << setiosflags(ios::fixed) << setprecision(5);
 
priority_queue<pll> k, c;
ll n, v, t, p, ans, lk, li, br;
bool skip = false;
vi his;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> v;
    F0R(i,n){
        cin >> t >> p;
        if(t == 1){
            k.push(mp(p,i+1));
        } 
        else{
            c.push(mp(p,i+1));
        }
    }
    while(v > 0 && k.size() + c.size() > 0){
        /*compare the expected value of both
        */
        if(!c.empty() && v == 1 && c.top().first > lk && k.empty()){
            if(lk == 0) return cout << 0, 0;
            ans += c.top().first;
            his.pb(c.top().second);
            ans -= lk;
            skip = true;
            v = 0;
        }
        else if(c.size() > 0 && c.top().first/2.0 >= k.top().first && v > 1 || k.size() == 0){
            v-=2;
            ans += c.top().first;
            his.pb(c.top().second);
            c.pop();
        }
        else if(c.size() == 0 || k.size() > 0 && c.top().first/2.0 < k.top().first || v == 1 && k.size() > 0){
            v-=1;
            ans += k.top().first;
            his.pb(k.top().second);
            lk = k.top().first;
            li = k.top().second;
            k.pop();
        }
        else if (v == 1 && k.empty()){
            break;
        }
        //cout << v << " " << k.size() + c.size() << endl;
        /*br++;
        if(br == 10001) cout << v << endl; break;*/
    } 
 
    cout << ans << endl;
    if(his.size()!=0){
        F0R(i,his.size()){
            if(skip && his[i] == li){
                continue;
            }
            cout << his[i] << " ";
        }
    }
    //cout << endl << v;
}
/*
Carrying capacity:
Find the optimum carrying capacity (ez, use a prio queue or set)

Truck body volume: v
n number of vehicles
t=type
p=capacity

Compare the top element of the priority queue of the number 2's
to the top element of the priority queue of the number 1's, use EV (obviously)

If there's an extra space in the van 
get rid of the lowest EV 1 and put in a two in it's place (after comparing total value)

1 1
1 600

THANK GOD
This was such as dumb-ass problem: Be precise with your implementation and should be fine
Otherwise it was a pain in the ass to debug
*/