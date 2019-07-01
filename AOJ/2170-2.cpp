// 愚直解法 (通っちゃう)
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)

using namespace std;

constexpr int kMaxN = 100000;
constexpr int kMaxQ = 100000;

struct Op {
  char com;
  int idx;
};

int N,Q;
int par[kMaxN];
vector<bool> marked;
vector<Op> ops;

void Init(void) {

  marked.resize(N);
  fill(marked.begin(), marked.end(), false);
  marked[0] = true;

}

int dfs(int i) {
  if (marked[i]) return i;
  return dfs(par[i]);
}

void solve(void) {
  Init();

  int ans = 0;
  for (auto op : ops) {
    if (op.com == 'Q') {
      ans += dfs(op.idx) + 1;
    } else {
      marked[op.idx] = true;
    }
  }
  cout << ans << endl;
}

signed main(void) {
  while(true) {
    cin >> N >> Q;
    if ( N == 0 && Q == 0) break;
    par[0] = 0;
    rep (i, N-1) {
      cin >> par[i+1];
      par[i+1]--;
    }
    ops.resize(Q);
    rep (i,Q) {
      cin >> ops[i].com >> ops[i].idx;
      ops[i].idx--;
    }
    solve();
  }

}