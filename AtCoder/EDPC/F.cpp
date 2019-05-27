#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>

using  ll = long long;
using ull = unsigned long long;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};
constexpr ll kINF = 1152921504606846976;//2^60
constexpr double kEPS = 1e-6;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define rep(i,n) REP(i,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep(i,n) RREP(i,n)
#define mp make_pair
#define fi first
#define sc second

using P = pair<int, int>;

template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false;}
string s,t; 
int dp[3010][3010];

P from[3010][3010];
int main(void) {
  cin >> s >> t;

  int n = s.length();
  int m = t.length();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      if (dp[i - 1][j] >= dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j];
        from[i][j] = P(i - 1, j);
      } else {
        dp[i][j] = dp[i][j - 1];
        from[i][j] = P(i, j - 1);
      }
      if (s[i - 1] == t[j - 1]) {
        if(chmax(dp[i][j], dp[i - 1][j - 1] + 1)) {
          from[i][j] = P(i - 1, j - 1);
        }
      }
    }
  }

  int i = n, j = m;

  string ans;

  while( i > 0 && j > 0) {
    P f = from[i][j];
    if ( i - f.first > 0 && j - f.second > 0) {
      ans.push_back(s[f.first]);
    } 
    i = f.first;j = f.second;
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;

  return 0;
}