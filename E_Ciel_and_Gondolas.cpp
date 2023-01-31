#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define O4 __inline__ __attribute__((always_inline))
#ifdef ONLINE_JUDGE
#define getchar nc
#endif
#define endl "\n"
namespace FastIO{
	O4 char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
	}
	O4 int read(){
		char t;int u=0,k=1;t=getchar();
		while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
		while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
		return u*k;
	}
  O4 long long readll(){
    char t;long long u=0,k=1;t=getchar();
    while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
    while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
    return u*k;
  }
}
using namespace FastIO; 
//tip for better performance: inline
const int N = 4005, K = 805;
int n, k, a[N][N], pre[N][N], dp[N][K], query[N][N], opt[N][K];
inline void solve(int dep, int rngL, int rngR, int optL, int optR){
  if(rngL > rngR) return;
  int mid = (rngL + rngR) >> 1;
  dp[mid][dep] = 0x3f3f3f3f;
  //every time the for loop checks half at max
  for(int i = optL; i <= min(mid, optR); i++){
    int tmp = dp[i][dep - 1] + query[i + 1][mid];
    if(tmp < dp[mid][dep]){
      dp[mid][dep] = tmp;
      opt[mid][dep] = i;
    }
  }
  //time complexity O(nlogn * k)
  solve(dep, rngL, mid - 1, optL, opt[mid][dep]);
  solve(dep, mid + 1, rngR, opt[mid][dep], optR);
}
int main(){
  scanf("%d%d", &n, &k);
  //memset(dp, 0x3f, sizeof(dp));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &a[i][j]);
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = i; j >= 0; j--){
      if(i == j) pre[i][j] = 0;
      else pre[j][i] = pre[i][j] = pre[i][j + 1] + a[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      if(i == j) query[i][j] = 0;
      else query[i][j] = pre[i][j] + query[i][j-1];
    }
  }
  for(int i = 0; i < n; i++){
    dp[i][1] = query[0][i];
  }
  for(int i = 2; i <= k; i++){
    solve(i, 0, n - 1, 0, n - 1);
  }
  //printf("%d", dp[n - 1][k]);
  //printf("%I64d", duration.count());
  printf("%d", dp[n - 1][k]);
}