#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
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

ll N;
double p[3000];
double dp[3000][3000];

int main(void) {
  cin >> N;
  rep(i, N) cin >> p[i];

  rep(i,N) rep(j, N) dp[i][j] = 0.0;
  dp[0][0] = 1.0;

  rep (i, N) {
    rep (j, N) {
      dp[i + 1][j + 1] += p[i] * dp[i][j];
      dp[i + 1][j] += (1.0 - p[i]) * dp[i][j];
    }
  }

  double ans = 0.0;
  rep (i,N + 1) if (i >= N / 2 + 1) ans += dp[N][i]; 

  printf("%.15f\n", ans);
  return 0;
}