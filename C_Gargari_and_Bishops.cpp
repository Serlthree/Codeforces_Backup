#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[2001][2001];
map<int, int> m1, m2;
struct custom_tuple
{
  int x, y, val;
  custom_tuple(int x, int y, int val) : x(x), y(y), val(val) {}
  bool operator<(const custom_tuple &t) const
  {
    return val < t.val;
  }
};
priority_queue<custom_tuple> pq;
vector<custom_tuple> v;
bool findIntersection(custom_tuple t1, custom_tuple t2)
{
  //case 1
  if (t1.y - t1.x == t2.y - t2.x)
    return true;
  //case 2
  if((t2.x - t1.x + t1.y + t2.y)%2 == 0)
    return true;
  //case 3
  if(t1.x + t1.y == t2.x + t2.y)
    return true;
  return false;
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }
  // get sum of diagonals
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      m1[i + j] += a[i][j];
      m2[i - j + n - 1] += a[i][j];
    }
  }
  // for each space, get the sum of the 2 diagonals
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      pq.push(custom_tuple(i, j, m1[i + j] + m2[i - j + n - 1] - a[i][j]));
    }
  }
  //test find intersection
  while (pq.size()){
    custom_tuple t = pq.top();
    pq.pop();
    v.push_back(t);
    for(int i = 0; i < v.size(); i++){
      // make sure there is no overlap
      if(findIntersection(v[i], t))
        continue;
      cout << v[i].val + t.val << "\n";
      cout << v[i].x + 1 << " " << v[i].y + 1 << " " << t.x + 1 << " " << t.y + 1;
      return 0;
    }
  }
  // time complexity: O(n^2 log n^2) -> O(n^2 log n)
}
/*
0 1
1 2 - represented by m1[i+j]

1 0
2 1 - represented by m2[i-j+n-1]
*/