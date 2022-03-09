#include<bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b) { return a ? gcd( b % a, a ) : b; }
 
const int L = 17;
const int S = 1 << L;
const int MAXS = S * 2 + 20;
 
const int MAXN = 1.2e5;
int N;
int A[MAXN];
 
int seg[MAXS];
int getgcd(int a, int b) {
	//traverses through the segment tree
	int res = 0;
	for(a += S, b += S; a < b; a /= 2, b /= 2) {
		//since seg trees don't work with odds, this gathers 
		if(a % 2) res = gcd(res, seg[a++]);
		if(b % 2) res = gcd(res, seg[--b]);
	}
	return res;
}
 
typedef pair<int, int> pii;
pii vals[MAXN];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		seg[i + S] = A[i];
		vals[i] = pii(A[i], i);
	}
	for(int i = S - 1; i > 0; i--) {
		seg[i] = gcd(seg[2 * i], seg[2 * i + 1]);
	}
	//You need this for the binary search
	sort(vals, vals + N);
 
	int T; cin >> T;
	for(int i = 0; i < T; i++) {
		int l, r; cin >> l >> r;
		l--;
		int g = getgcd(l, r);
		int res = lower_bound(vals, vals + N, pii(g, r)) - lower_bound(vals, vals + N, pii(g, l)); 
		//Counts number
		cout << r - l - res << '\n';
	}
	return 0;
}
/*
detailed explanation of how this algorithm works:
5
Create a segment tree:
1 3 2 4 2 this gets stored in 2*n
1 2 2 this gets stored in n
1 2 this gets stored in n/2
1 this gets stored in n/4's (so on)

What this represents in set:
1 2 3 4 5
1-2 3-4 5
1-4 5
1-5

Why segment trees? Answer RMQ's faster (numbers that you need a range to answer)
1 5 
gcd is 1: since there is a 1 therefore 4 gets eaten

2 5
You need gcd(2), get gcd(3,4), and gcd(5)
(You get 3 2 2)
gcd = 1
Notice there is not a single 1: 4 (Use binary search to find it)

3 5 
You need gcd(3,4) and gcd(5)
(You get 2 2)
gcd = 2 
Find 2's location: notice that everything encapsulating the 2's are multiples of 2's
(There are 2 2's)

*/