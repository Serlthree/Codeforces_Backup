#include <bits/stdc++.h>
using namespace std;
int t, a[9][9];
bool r[9], c[9], b[9];
vector<pair<int, int>> v;
char num;
int main()
{
  cin >> t;
  while (t--)
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cin >> num;
        a[i][j] = num - '0';
      }
    }
    for (int i = 1; i <= 9; i++)
    {
      memset(r, 0, sizeof(r));
      memset(c, 0, sizeof(c));
      memset(b, 0, sizeof(b));
      v.clear();
      for (int j = 0; j < 9; j++)
      {
        for (int k = 0; k < 9; k++)
        {
          if (a[j][k] != i && !r[j] && !c[k] && !b[(j / 3) * 3 + k / 3])
          {
            r[j] = true;
            c[k] = true;
            b[(j / 3) * 3 + k / 3] = true;
            v.push_back({j, k});
          }
        }
      }
      if(v.size() == 9){
        for(int j = 0; j < 9; j++){
          a[v[j].first][v[j].second] = i;
        }
        //print the ans
        for(int j = 0; j < 9; j++){
          for(int k = 0; k < 9; k++){
            cout << a[j][k];
          }
          cout << "\n";
        }
        goto end;
      }
    }
    end:;
  }
}