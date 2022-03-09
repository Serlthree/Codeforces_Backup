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

char b[3][3];
int o, x;
int checkWin(char c){
    int res = 0;
    bool d, r, v;
    //check row cols diagonals
    F0R(i,3){
        if(b[i][0] == c && b[i][1] == c && b[i][2] == c){
            res++;
            r = true;
        }
    }
    F0R(i,3){
        if(b[0][i] == c && b[1][i] == c && b[2][i] == c){
            res++;
            v = true;
        }
    }
    if(b[0][0] == c && b[1][1] == c && b[2][2] == c){
        res++;
        d = true;
    }
    if(b[0][2] == c && b[1][1] == c && b[2][0] == c){
        res++;
        d = true;
    }
    if(res == 2){
        if(d && (v || r)){
            if(v != r){
                return res;
            }
            else{
                res = -1; 
            }
        }
        else{
            res = -1;
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    F0R(i,9){
        cin >> b[i/3][i%3];
        if(b[i/3][i%3] == '0'){
            o++;
        }
        else if(b[i/3][i%3] == 'X'){
            x++;
        }
    }
    //X's go first, O's go second
    /*
    Illegal Boards take priority first,
    Winning/Draw boards take priority second
    First/Second boards take last priority

    Some niche things to worry about:
    -You can't win twice at some direction (obviously)
    XOX
    OXO
    XOX (this board is legal)

    XO0
    OXO
    XXX (this board is legal)

    XXX
    XXX //This doesn't satisfy the requirements in the first place
    OOO

    Just another illegal board:
    000
    X.X
    X.X
    -Both players can't win
    The only wins that count are diagonal wins or vertical cross wins. The rest do not count
    */
    if(x > o + 1 || x < o || (checkWin('0') >= 1 && checkWin('X') >= 1) || (checkWin('X') == -1 || checkWin('0')) == -1 || (x == o + 1 && checkWin('0')) || (x == o && checkWin('X'))){
        cout << "illegal";
        /*cout  << x << " " << o;*/
        /*cout << checkWin('0') << " " << checkWin('X');*/
    }
    else if (checkWin('0')){
        cout << "the second player won";
    }
    else if (checkWin('X')){
        cout << "the first player won";
    }
    else if (x == 5 && o == 4){
        cout << "draw";
    }
    else if (x == o){
        cout << "first"; 
    }
    else if (x == o + 1){
        cout << "second";
    }
}