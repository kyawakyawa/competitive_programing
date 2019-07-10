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

#define  int long long
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};
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

const int inf = 1e18;

int N;
int c[40000];

int dp[40000];
bool used[40000];

void init (void) {
  rep(i,N) dp[i] = inf;
}

void solve(void) {
  init();

  rep(j,N) {
    *lower_bound(dp, dp+N, c[j]) = c[j];
  }

  int i = 0;
  for (i = 0;i < N;i++) {
    if (dp[i] == inf) break;
  }

  cout << N - i << endl;

}

signed main(void) {
  cin >> N;
  rep(i,N) {
    cin >> c[i];
  }
  solve();
}