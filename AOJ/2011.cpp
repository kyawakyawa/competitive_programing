#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

int n;
vector<int> d[31];
int dp[50];

void init(void) {
  rep(i,31) d[i].clear();
}

void init_dp(void) {
  rep(j,n) {
    dp[j] = (1 << j);
  }
}

void solve(void) {
  init_dp();

  for(int i = 1; i < 31;i++) {
    int next = 0;
    for (auto v : d[i]) {
      next |= dp[v];
    }
    for (auto v : d[i]) {
      dp[v] = next;
    }
    rep (j,n) {
      if (dp[j] == (1 << n) - 1) {
        cout << i << endl;
        return;
      }
    }
  }
  cout << -1 << endl;

}
signed main(void) {
  while (true) {
    init();
    cin >> n;
    if (n == 0) break;
    rep(i, n) {
      int f;
      cin >> f;
      rep(j, f) {
        int tmp;
        cin >> tmp;
        d[tmp].push_back(i);
      }
    }
    solve();
  }
}

