#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

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

string s;
ll bracket_count, left_cost, right_cost, total_cost;
set<pii> st;
int main(){
    quick;
    cin >> s;
    F0R(i,s.size()){
        if(s[i] == '('){
            bracket_count++;
        }
        else if(s[i] == ')'){
            bracket_count--;
        }
        else{
            //Auto insert the ')'
            cin >> left_cost >> right_cost;
            //Sort by cost
            st.insert(mp(left_cost-right_cost,i));
            total_cost += right_cost;
            bracket_count--;
            s[i] = ')';
        }
        //Note: Sets auto sort
        if(bracket_count < 0 && !st.empty()){
            bracket_count+=2;
            s[(*st.begin()).second] = '(';
            total_cost += (*st.begin()).first;
            st.erase(st.begin());
        }
        if(bracket_count < 0) break; //account for invalid sources
    }
    if(bracket_count != 0){
        cout << -1;
    }
    else{
        cout <<  total_cost << endl << s;
    }
}
/*
Bracket Sequence Algorithm:
1. First place everything with rights brackets
2. If there's too many left brackets take the least cost and place a right bracket there
3. Store it in a set/pqueue and this will automatically sort by least cost.
*/
