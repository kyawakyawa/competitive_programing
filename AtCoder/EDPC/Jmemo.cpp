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

double memo[310][310][310];
bool done[310][310][310];

ll N;
ll a[300];

double rec(ll j,ll k, ll l) {
  if (done[j][k][l]) return memo[j][k][l];

  double ret = 0.0;

  ll i = N - j - k - l;

  double p = (double)i / (i + j + k + l);

  if (j > 0) ret += rec(j-1, k, l)   * (double)j / (j + k + l) + 1 / (1 - p) / (1 - p) * ((double)j / (i + j + k + l));
  if (k > 0) ret += rec(j+1, k-1, l) * (double)k / (j + k + l) + 1 / (1 - p) / (1 - p) * ((double)k / (i + j + k + l));
  if (l > 0) ret += rec(j, k+1, l-1) * (double)l / (j + k + l) + 1 / (1 - p) / (1 - p) * ((double)l / (i + j + k + l));

  done[j][k][l] = true;
  return memo[j][k][l] = ret;
}

int main(void) {
  cin >> N;
  rep (i, N) cin >> a[i];

  ll c[4];
  rep(i,4)c[i] = 0;
  rep(i, N) {
    c[a[i]]++;
  }
  printf("%.15f\n", rec(c[1], c[2], c[3]));
  return 0;
}