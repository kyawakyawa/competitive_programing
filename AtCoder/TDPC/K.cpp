#include <iostream>
#include <algorithm>

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++) 

using namespace std;
using P = pair<int,int>; 
int N;
P c[100000];
int dp[100000];
const int inf = 1e18;
signed main(void) {
  cin >> N;
  rep (i,N) {
    int x,r;
    cin >> x >> r;
    c[i] = P(x - r, x + r);
  }

  sort(c, c + N, greater<P>() );

  rep (i, N) dp[i] = inf;

  rep (i,N) {
    *lower_bound(dp, dp+N, c[i].second) = c[i].second;
  }

  cout << lower_bound(dp, dp+N, inf) - dp << endl;
  return 0;
}