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

int rkp, ckp, rendSq, cendSq, cnt, r, c;
char convck, convcend;
int main(){
    ios::sync_with_stdio(false);
    cin >> convck >> rkp >> convcend >> rendSq;
    ckp = convck - 'a'; cendSq = convcend - 'a';
    r = cendSq - ckp; //calculate steps needed to move right
    c = rendSq -  rkp; //calculate steps needed to move up
    //the max amount of moves it could take is the max of the two numbers
    int res = max(abs(r), abs(c));
    cout << res << endl;
    F0R(i,res){
        if(r > 0 && c > 0){
            cout << "RU" << endl;
            r--;
            c--;
        }
        else if(r == 0 && c > 0){
            cout << "U" << endl;
            c--;
        }
        else if(r > 0 && c == 0){
            cout << "R" << endl;
            r--;
        }
        else if(r > 0 && c < 0){
            cout << "RD" << endl;
            r--;
            c++;
        }
        else if(r < 0 && c == 0){
            cout << "L" << endl;
            r++;
        }
        else if(r == 0 && c < 0){
            cout << "D" << endl;
            c++;
        }
        else if(r < 0 && c > 0){
            cout << "LU" << endl;
            r++;
            c--;
        }
        else if(r < 0 && c < 0){
            cout << "LD" << endl;
            r++;
            c++;
        }
    }
}