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

ll N,K;
ll h[100010];
ll dp[100010];

template<class T> bool chmin(T& a, const T b) {if (a > b) { a = b; return true;} return false;}

int main(void) {
  cin >> N >> K;
  rep(i,N) {
    cin >> h[i];
    dp[i] = kINF;
  }
  dp[0] = 0;

  rep (i,N-1) {
    for (int j = 1; j <= K && i + j < N;j++) {
      chmin(dp[i+j],dp[i] + abs(h[i+j] - h[i]));
    }
  }
  cout << dp[N - 1] << endl;
}