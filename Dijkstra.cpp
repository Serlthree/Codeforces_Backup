#include <bits/stdc++.h>
using namespace std;
 
template <class T> inline T sqr(const T& x) { return x * x; }//NOTES: sqr(
template<class T> inline void checkmin(T& a, T b) { if (b < a) a = b; }//NOTES:checkmin(
template<class T> inline void checkmax(T& a, T b) { if (b > a) a = b; }//NOTES:checkmax(
 
#define ld long double
#define ll long long
#define pb push_back
#define mp make_pair
#define F0R(i,j) for(int i = 0; i < (int)j; i++)
#define FOR(i,j,k) for (int i = j; i < (int)k; i++)
#define FORE(i,j,k) for(int i = j; i <= (int)k; i++)
#define FORN(i, n) for(int i=(n)-1; i>=0; i--)
 
const ll INF = 1e18;
 
vector<pair<ll, ll>>g[100001];
set<pair<ll, ll>>S;
vector<int>ans;
int n, m;
ll d[100001], p[100001]; //d = distance, p = visited
 
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	F0R(i, m) {
		int ai, bi, wi;
		cin >> ai >> bi >> wi;
		g[ai].pb(mp((ll)bi, (ll)wi)); //this gets stored index, weight
		g[bi].pb(mp((ll)ai, (ll)wi));
	}
	fill(d, d + n + 1, INF);
	d[1] = 0; //Starting vertex shortest path = 0
	S.insert(mp(d[1], 1)); //This stores the vertex + current distance
	while (!S.empty()) {
		int v = S.begin()->second; //Gets the vertex
		S.erase(S.begin());
		F0R(i, g[v].size()) { //iterates through the adjacency list
			ll u = g[v][i].first, l = g[v][i].second; //u = connecting index, l = weight
			if (d[u] > d[v] + l) { //updates d[u] (minimum length) 
				S.erase(mp(d[u], u)); //erases the old value of u if there is one
				d[u] = d[v] + l;
				p[u] = v; //updates to point to the previous index (helps with path finding)
				S.insert(mp(d[u], u));
			}
		}
	}
	if (d[n] == INF) {
		cout << -1;
	}
	else {
		int v = n;
		while (v != 1) {
			ans.pb(v);
			v = p[v];
		}
		ans.pb(1);
		FORN(i, ans.size()) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}