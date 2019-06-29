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

using P = pair<ll,ll>;

ll n;
ll deg[1000];
ll p[1000],d[1000];
vector<P> G[1000];
ll used[1000];

ll dfs(int i) {
  ll ret = 0;
  for (auto e : G[i]) {
    if (used[e.second] || deg[e.second] == 1) continue;
    used[e.second] = true;

    ret = max(ret, e.first + dfs(e.second));
  }
  return ret;
}

void solve() {
  ll sum = 0;
  rep (i,n) {
    if (i == 0) continue;
    if (deg[i] == 1 || deg[p[i]] == 1) {
      sum += d[i];
    } else {
      sum += 3 * d[i];
    }
  }
  ll ans = sum;
  rep (i,n) {
    if (deg[i] <= 1) continue;
    rep (j,n) used[j] = false;
    used[i] = true;
    ll r = dfs(i);
    ans = min(ans, sum - r);
  }
  cout << ans << endl;
}

int main(void) {
  while(true) {
    cin >> n;
    if (n==0) break;
    rep (i,n) {
      G[i].clear();
      deg[i] = 0;
    }
    rep (i,n) {
      if (i == 0) continue;
      cin >> p[i];
    }
    rep (i,n) {
      if (i == 0) continue;
      cin >> d[i];
    }
    rep (i,n) {
      if (i == 0)continue;
      p[i]--;
      G[i].push_back(P(d[i],p[i]));
      G[p[i]].push_back(P(d[i],i));
      deg[p[i]]++;deg[i]++;
    }

    solve();
  }
}