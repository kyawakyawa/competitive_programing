#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using ll = long long;
struct E {
  ll to;
  ll c;
};

ll n;
ll k;
ll s;
ll x[3000],y[3000],z[3000];
vector<vector<E>> G;
vector<bool> used;


void dfs(int i, vector<ll>& m){
  for (auto v : G[i]) {
    if (!used[v.to]) {
      used[v.to] = true;
      m.push_back(v.to);
      dfs(v.to, m);
      break;
    }
  }
}

ll con (int i, int j) {
  for (auto e : G[i]) {
    if (j == e.to) {
      return e.c;
    }
  }
  return 0;
}

void solve(void) {
  G.clear();

  rep (i,n) G.push_back(vector<E>());

  rep(i,n) {
    rep (j,n) {
      if (i >= j) continue;

      ll xd = s - abs(x[i] - x[j]);
      ll yd = s - abs(y[i] - y[j]);
      ll zd = s - abs(z[i] - z[j]);
      if (xd <= 0 || yd <= 0 || zd <= 0) continue;
      ll cm = -2 * (xd * yd + yd * zd + zd * xd);
      G[i].push_back((E){j,cm});
      G[j].push_back((E){i,cm});
    }
  }

  used.resize(n);
  ll ans = 0;
  rep (i,n) {
    vector<ll> vs;
    fill(used.begin(), used.end(), false);
    vs.push_back(i);
    used[i] = true;
    dfs(i, vs);

    if (vs.size() < k || k == 1) continue;
    bool flag = false;
    if (k >= 3 && con(vs[0],vs.back()) != 0) {
      flag = true;
    }

    if (flag && vs.size() == k) {
      ll sum = 0;
      rep (i,vs.size() - 1) {
        sum += con(vs[i],vs[i+1]);
      }
      sum += con(vs[0], vs.back());
      ans = min(ans, sum);
    } else {
      ll sum = 0;
      rep (i, vs.size()) {
        if (i == 0) {
          rep (j, k-1) {
            sum += con(vs[j], vs[j+1]);
          }
        } else {
          if (!flag && i + k - 1 >= vs.size()) break;
          sum += con(vs[(i + k - 2) % vs.size()], vs[(i + k - 1) % vs.size()]) - con(vs[i - 1], vs[i]);
        }
        ans = min(sum, ans);
      }
    }
  }
  if (k > 1 && ans == 0) cout << -1 << endl;
  else cout << s * s * 6 * k + ans << endl;
}

signed main (void) {
  while(true) {
    cin >> n >> k >> s;
    if (n == 0) break;

    rep (i,n) cin >> x[i] >> y[i] >> z[i];
    solve();
  }
}