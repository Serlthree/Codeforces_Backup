#include <bits/stdc++.h>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
const double pi = 3.141592653589793238;
const int INF = 1000000000;

#define quick ios::sync_with_stdio(false); cin.tie(0) 
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

const int MAXV = (int)1e5+1;
vector<pii>graph[MAXV];
int n, sz[MAXV], removed[MAXV], ans[MAXV];
//NOTE: Ordering of functions matters


void dfs(int p, int x){
	//p = previous node x = new node
	sz[x] = 1;
	F0R(i,graph[x].size()){
		int y = graph[x][i].first;
		if(y != p && !removed[y]){
			dfs(x,y);
			sz[x] += sz[y]; //DETAILED explanation below.
		}
	}
}
int find_center(int x){
	int p = -1;
	dfs(-1,x); //You need to find total number of nodes contained in each part
	int cap = sz[x]/2;
	while(true){
		bool found = false;
		F0R(i,graph[x].size()){
			int y = graph[x][i].first;
			if(!removed[y] && y != p && sz[y] > cap){
				found = true;
				p = x;
				x = y;
				break;
			}
		}
		if(!found) return x; //if sz[y] > cap break, if it doesn't find anything it's the middle
	}
}
void func(int x, int alp){
	int y = find_center(x); //finds the center
	ans[y] = alp; //alp = alpha node (main node)
	removed[y] = true;
	F0R(i,graph[y].size()){
		int z = graph[y][i].first;
		if(!removed[z]) func(z,alp+1);
	} 
}
int main(){
	quick;
	cin >> n;
	F0R(i,n-1){
		int a, b;
		cin >> a >> b;
		graph[a-1].pb(mp(b-1,1));
		graph[b-1].pb(mp(a-1,1));
		//creates the graph (note adjancency list setup + no weights are needed)
	}
	func(0,0);
	//prints the answer
	F0R(i,n){
		cout << (char)(ans[i] + 'A');
		if(i != n - 1){
			cout << ' '; 
		}
	}
}
/*
Idea: Find the centroid of the tree
Put the centroid as A
Put the rest as B's etc

What does sz do?
Say this is a graph
   1
2    3
4 5  6

What this does:
  6 - total
3 -number of nodes for node 2   2 - number of nodes for node 3
1 1 1

Algorithm Process:
1. Find the center (center becomes A)
2. Remove the center and find the other centers of the two subnodes
Repeat

Time Complexity: Finding the center requires trasversing all edges (V)
repeating requires log(n) time because of decomposition
*/