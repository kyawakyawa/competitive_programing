#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

int n;
vector<int> d[31];
int memo[31][50];
bool done[31][50];

void init(void) {
  rep(i,31) d[i].clear();
}

void init_dp(void) {
  rep(i,31) {
    rep(j,n) {
      done[i][j] = false;
    }
  }
}

int rec(int i, int j) {
  if (i == 0) {
    done [i][j] = true;
    return memo[i][j] = 1ll<<j;
  }
  if (done[i][j]) return memo[i][j];
  bool flag = false;
  for (auto v : d[i]) {
    if (v == j) flag = true;
  }

  int ret = 0;
  if (flag) {
    for (auto v : d[i]) {
      ret |= rec(i - 1, v);
    }
  } else {
    ret = rec(i - 1, j);
  }
  done[i][j] = true;
  return memo[i][j] = ret;
}

void solve(void) {
  init_dp();
  rep(j,n) rec(30, j);

  rep(i,31) {
    rep(j,n) {
      if (memo[i][j] == ((1ll << n)-1)) {
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

