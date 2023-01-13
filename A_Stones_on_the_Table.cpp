#include <bits/stdc++.h>
using namespace std;

char s[50];
int main(){
  int n, ans = 0;
  scanf("%d", &n);
  scanf("%s", s);
  for(int i = 1; i < n; i++){
    if(s[i] == s[i-1]) ans++;
  }
  printf("%d", ans);
}