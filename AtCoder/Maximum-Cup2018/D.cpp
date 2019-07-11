#include <iostream>
#include <algorithm>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int inf = 1e18;

signed main(void) {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int N,M,L,X,a[10001];
  int dp[2][1000];
  cin >> N >> M >> L >> X;
  rep (i,N) cin >> a[i+1];

  rep (j, M) dp[0][j] = inf;
  dp[0][0] = 0;

  for (int i = 1;i <= N; i++) {
    for (int j = 0; j < M; j++) {
      int s = (j - a[i]) % M;
      if (s < 0) s += M;
      dp[i & 1][j] = min(dp[(i+1)&1][j], dp[(i+1) & 1][s] + (s + a[i]) / M);
    }
  }
  if (dp[N & 1][L] < X) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}