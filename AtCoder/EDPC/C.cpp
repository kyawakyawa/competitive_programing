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

ll N;
ll a[3][100010];
ll dp[100010][3];

template<class T>bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

int main(void) {
  cin >> N;

  rep(i,N) cin >> a[0][i] >> a[1][i] >> a[2][i];

  rep(i,N) {
    rep(j,3) {
      rep(k,3) {
        if (j == k)continue;
        chmax(dp[i + 1][k],dp[i][j] + a[k][i]);
      }
    }
  }

  cout << max(dp[N][0], max(dp[N][1],dp[N][2])) << endl;

  return 0;
}