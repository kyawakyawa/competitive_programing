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

using P = pair<ll,ll>;
using Q = pair<P,P>;

map<Q, double> memo;

ll N;
ll a[300];

double rec(Q q) {
  if (memo.find(q) != memo.end()) return memo[q];

  double ret = 0.0;

  ll i = q.first.first;
  ll j = q.first.second;
  ll k = q.second.first;
  ll l = q.second.second;

  double p = (double)i / (i + j + k + l);

  if (j > 0) ret += rec(Q(P(i+1,j-1),P(k,l))) * (double)j / (j + k + l) + 1 / (1 - p) / (1 - p) * ((double)j / (i + j + k + l));
  if (k > 0) ret += rec(Q(P(i,j+1),P(k-1,l))) * (double)k / (j + k + l) + 1 / (1 - p) / (1 - p) * ((double)k / (i + j + k + l));
  if (l > 0) ret += rec(Q(P(i,j),P(k+1,l-1))) * (double)l / (j + k + l) + 1 / (1 - p) / (1 - p) * ((double)l / (i + j + k + l));

  return memo[q] = ret;
}

double dp[310][310][310];

int main(void) {
  cin >> N;
  rep (i, N) cin >> a[i];

  ll c[4];
  rep(i,4)c[i] = 0;
  rep(i, N) {
    c[a[i]]++;
  }

  rep(l, N+1) {
    rep(k, N+1) {
      if (l + k > N) break;
      rep(j, N+1) {
        ll i = N - j - k - l;
        if (i < 0) break;
        if (i == N) {
          dp[j][k][l] = 0.0f;
          continue;
        }
        dp[j][k][l] = 1.0;
        if (j > 0) dp[j][k][l] += dp[j-1][k][l]   * (double)j / N;
        if (k > 0) dp[j][k][l] += dp[j+1][k-1][l] * (double)k / N;
        if (l > 0) dp[j][k][l] += dp[j][k+1][l-1] * (double)l / N;
        double p = (double)i / N;
        dp[j][k][l] /= (1 - p);
      }
    }
  }

  printf("%.15f\n", dp[c[1]][c[2]][c[3]]);
  return 0;
}