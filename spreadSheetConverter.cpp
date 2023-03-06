#include <bits/stdc++.h>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
const double pi = 3.141592653589793238;
const int INF = 1000000000;
 
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
#define vi vector<int>
#define se second
#define fi first
#define si(x) scanf("%d",&x)
#define sf scanf
#define pf printf

int n, r, c, x;
char s[64], *p;
void convert(int col){
    if (col){
        convert((col-1)/26);
        putchar((col-1)%26 + 'A');
        /*
        Explanation: Test 26
        26/26 = 1 so it will put an unecessary A in
        26%26 = 0 so it will put a 'A' in as well 
        */
    }
}
int main(){
    cin >> n;
    F0R(i,n){
        cin >> s;
        if(sscanf(s,"%*c%d%*c%d",&r,&c) == 2){
            convert(c);
            cout << r << endl;
        }
        else{
            x = 0;
            for(p = s; *p >= 'A'; p++){
                x = x * 26 + *p - 'A' + 1;
                //x = *p - 'A' + 1;
            }
            cout << "R" << p << "C" << x << endl;
        }
    }
}
/*
Test Cases:
X83
Answer:
R83C24

RZ228

R228C494
*/