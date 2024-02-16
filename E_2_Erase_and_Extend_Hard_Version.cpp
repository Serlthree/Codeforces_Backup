#include <bits/stdc++.h>
using namespace std;
char s[500005];
int n, k, l, p = 1;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s;
  while(++l < n){
    if(s[l] > s[l%p]) break;
    if(s[l] < s[l%p]) p = l+1; //compares l to p
  }
  for(int i = 0; i < k; i++){
    cout << s[i%p];
  }
}
/*
Insight 1: Really easy proof that you only need to consider deleting before you start duplicating
Insight 2: This is a really easy way to compare prefixes (two pointers, compare prefix of length l to prefix of length p)
*/