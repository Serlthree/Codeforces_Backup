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

int n, m, MAX = -1e9, ai[1001];
map<string,int> M, MRedo;
string s, w, as[1001];

int main(){
    ios::sync_with_stdio(false);
	cin >> n;
	F0R(i,n){
		cin >> s >> m;
		M[s] = m + M[s];
		//Stores this in the string
		as[i] = s;
		ai[i] = m;
	}
	for(auto i : M){
		//Finds the max
		checkmax(MAX,i.second);
	}
	//redos the entire process
	F0R(i,n){
		if(M[as[i]] == MAX){
			MRedo[as[i]] = ai[i] + MRedo[as[i]];
			if(MRedo[as[i]] >= MAX){
				return cout << as[i], 0;
			}
		}
	}
}