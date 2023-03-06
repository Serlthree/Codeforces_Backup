/*
Make another array and retrace your steps back using that array!
Also: account for 0.
*/
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
 
string ress;
int n, a[1001][1001], m, res, numTwos, numFives, at[1001][1001], af[1001][1001];
char atc[1001][1001], afc[1001][1001];
int count(int num1, int num2){
    int cnt = 0;
    while(num1 % num2 == 0 && num1 != 0){
        num1 /= num2;
        cnt++;
    }
    return cnt;
}
void retrace(int r, int c, bool two){
    if(r == 0 && c == 0) return;
    //cout << r << c << endl;
    if(two){
        if(atc[r][c] == 'D'){
            retrace(r-1,c,true);
        }
        else if (atc[r][c] == 'R'){
            retrace(r,c-1,true);
        }
        cout << atc[r][c];
    }
    else{
        if(afc[r][c] == 'D'){
            retrace(r-1,c,false);
        }
        else if (afc[r][c] == 'R'){
            retrace(r,c-1,false);
        }
        cout << afc[r][c];
    }
}
int main(){
    ios::sync_with_stdio(false);
    //Simple DP Problem
    memset(at,1,sizeof(at));
    memset(af,1,sizeof(af));
    memset(atc,'0',sizeof(atc));
    memset(afc,'0',sizeof(afc));
    at[0][0] = 0;
    af[0][0] = 0;
    cin >> n;
    F0R(i,n){
        F0R(j,n){
            cin >> a[i][j];
        }
    }
    F0R(i,n){
        F0R(j,n){
            //take the min of the left and the right
            numTwos = count(a[i][j],2);
            numFives = count(a[i][j],5);
            //Fills array based on number of twos 
            at[i+1][j] = min(at[i][j]+numTwos,at[i+1][j]);
            at[i][j+1] = min(at[i][j]+numTwos,at[i][j+1]);
            if(at[i+1][j] == at[i][j] + numTwos){
                atc[i+1][j] = 'D';
            }
            if(at[i][j+1] == at[i][j] + numTwos){
                atc[i][j+1] = 'R';
            }
            //Fills array based on number of fives
            af[i+1][j] = min(af[i][j]+numFives,af[i+1][j]);
            af[i][j+1] = min(af[i][j]+numFives,af[i][j+1]);
            if(af[i+1][j] == af[i][j] + numFives){
                afc[i+1][j] = 'D';
            }
            if(af[i][j+1] == af[i][j] + numFives){
                afc[i][j+1] = 'R';
            }
            //the ifs are for retrevial
        }
    }
    res = min(at[n-1][n-1]+count(a[n-1][n-1],2),af[n-1][n-1]+count(a[n-1][n-1],5));
    /*F0R(i,n){
        F0R(j,n){
            cout << af[i][j];
        }
        cout << endl;
    }*/
    //Account for 0 somewhere
    F0R(i,n){
        F0R(j,n){
            if(res > 1 && a[i][j] == 0){
                cout << "1" << endl;
                F0R(k,i){
                    cout << "D";
                }
                F0R(l,j){
                    cout << "R";
                }
                F0R(i1,n-i-1){
                    cout << "D";
                }
                F0R(i2,n-j-1){
                    cout << "R"; 
                }
                return 0;
            }
        }
    }
    cout << res << endl;
    /*F0R(i,n){
        F0R(j,n){
            cout << atc[i][j] << " ";
        }
        cout << endl;
    }*/
    if(res == at[n-1][n-1]+count(a[n-1][n-1],2)){
        //cout << "TWO" << endl;
        retrace(n-1,n-1,true);
    }
    else{
        retrace(n-1,n-1,false);
    }
 
    //View numbers of products of 2's and 5's 
    //Also Print the Corresponding Way
    //cout << count(8,2);
}
/*
Case:
3
1 2 3
4 5 6
7 8 9


Case with 0:
5
2 2 2 2 2
5 5 5 5 5
2 2 0 2 2
5 5 5 5 5
5 2 5 2 5
*/