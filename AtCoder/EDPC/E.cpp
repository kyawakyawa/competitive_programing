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

ll N,W;
ll w[110],v[110],dp[110][100010];

template<class T> bool chmax (T &a, const T b) {if (a < b) {a = b; return true;}return false;}
template<class T> bool chmin (T &a, const T b) {if (a > b) {a = b; return true;}return false;}

int main(void) {
  cin >> N >> W;
  rep(i,N) cin >> w[i] >> v[i];

  ll V = 0;
  rep(i,N)V+=v[i];

  rep(i,N + 1) {
    rep(j,V+1) {
      dp[i][j] = kINF;
    }
  }

  dp[0][0] = 0;

  rep (i,N) {
    rep(j,V+1) {
      chmin(dp[i+1][j], dp[i][j]);
      if (j + v[i] <= V) chmin(dp[i+1][j+v[i]], dp[i][j]+w[i]);
    }
  }

  ll ans = 0;
  rep (i,N+1) {
    rep(j,V+1) {
      if (dp[i][j] <= W) chmax<ll>(ans, j);
    }
  }

  cout << ans << endl;
  return 0;
}
