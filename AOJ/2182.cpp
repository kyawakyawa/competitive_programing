#include <iostream>
#include <vector>
#include <string>

#define int long long

using namespace std;

vector<int> a;
int dp[100000][11];

void Init(void) {
  a.clear();
}

void dp_init(void) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < 11; j++) {
      dp[i][j] = 0;
    }
  }
}

void Prepro(void) {
  int m = -1;
  int l = 1;
  for (auto&v : a) {
    l *= m;
    v *= l;
  }
  for (auto&v : a) {
    if (v >= 0) {
      v %= 11;
    } else {
      v %= 11;
      v = 11 + v;
    }
  }
}

void Solve(void) {
  dp_init();

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < 11; j++) {
      if (a[i] > 0 && a[i] == j) {
        dp[i][j] += 1;
      }
      if (i > 0) dp[i][j] += dp[i - 1][(11 + j - a[i]) % 11];
    }
  }
  int ans = 0;
  for  (int i = 0;i < a.size(); i++) ans += dp[i][0];

  cout << ans << endl;
}

signed main(void) {
  while (true) {
    Init();
    string s;
    cin >> s;
    if (s.size() == 1 && s[0] == '0') break;
    for (auto c : s) {
      a.push_back(c - '0');
    }
    Prepro();
    Solve();
  }
}