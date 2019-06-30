#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int n,d,x;
int p[10][10];
int dp[11][100001];

template<typename T>
bool chmax(T &a, const T&b) {if(a < b) {a = b; return true;} return false;}

void init(void) {
  rep(i,n) rep(j,100001) dp[i][j] = 0;
}

void solve() {
  rep (i,d - 1) {
    vector<int> v;

    rep(j,n) {
      v.push_back(p[i+1][j]-p[i][j]);
    }

    init();

    rep (j, v.size()) {
      rep (k, x+1) {
        dp[j+1][k] = dp[j][k];
        if (k - p[i][j] >= 0) chmax(dp[j+1][k], dp[j+1][k - p[i][j]] + v[j]);
      }
    }

    x += dp[v.size()][x];
  }
  cout << x << endl;
}
signed main (void) {
  cin >> n >> d >> x;
  rep (i,d) rep(j,n) cin >> p[i][j];
  solve();
}