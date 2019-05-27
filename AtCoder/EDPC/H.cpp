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

ll H,W;
char a[1010][1010];

ll dp[1010][1010];

constexpr ll p = 1000000007;

static inline ll mod(ll a) {return a % p;}
static inline void modadd(ll& a, ll b) {a = mod(a + b);} 

int main(void) {
  cin >> H >> W;

  rep (i, H)
    cin >> &a[i][0];

  dp[0][0] = 1;

  rep (i, H) {
    rep (j, W) {
      if (a[i][j] == '#') continue;

      if (i > 0) modadd(dp[i][j], dp[i - 1][j]);
      if (j > 0) modadd(dp[i][j], dp[i][j - 1]);
    }
  }

  cout << dp[H-1][W-1] << endl;
}