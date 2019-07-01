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

///-----
int ma[kMaxN];
int urank[kMaxN];
int color[kMaxN];
void init() {
  rep (i,kMaxN) {
    ma[i] = i;
    urank[i] = 0;
    color[i] = i;
  }
}

int find(int x) {
  if (ma[x] == x)return x;
  return ma[x] = find(ma[x]);
}

void unite(int x, int y) { // xの方の色にする
  x = find(x);
  y = find(y);

  if (x == y) return;

  color[y] = color[x];

  if (urank[x] < urank[y]) {
    ma[x] = y;
  } else {
    ma[y] = x;
    if (urank[x] == urank[y]) urank[x]++;
  }
}

int get_now_color(int x) {
  x = find(x);
  return color[x];
}

///-----
using P = pair<char,int>;

struct Op {
  char com;
  int idx;
};

int N,Q;
int par[kMaxN];
vector<int> col;
vector<int> G[kMaxN];
vector<Op> ops;
vector<bool> used;

void Init(void) {
  used.resize(N);
  fill(used.begin(), used.end(), false);

  col.resize(N);
  rep (i,N) col[i] = -1;
  set<int> S;
  S.insert(0);
  for (auto &op:ops) { // 同じノードを複数回塗るときは最初のクエリだけ有効にする
    if (op.com == 'Q') continue;
    if (S.find(op.idx) != S.end()) {
      op.idx = -1;
    } else {
      S.insert(op.idx);
    }
  }
  for (auto op : ops) if (op.com == 'M' && op.idx >= 0) col[op.idx] = op.idx;
  col[0] = 0;
}

void dfs(int i, int c) {
  if (used[i]) return;
  used[i] = true;
  if (col[i] >= 0) c = col[i];
  else col[i] = c;

  for (auto e : G[i]) {
    dfs(e, c);
  }
}
void solve(void) {
  Init();

  dfs(0,0);

  init();
  int ans = 0;
  for (int i = Q - 1; i >= 0; i--) {
    auto& op = ops[i];

    if (op.com == 'M') {
      if (op.idx < 0) continue;
      int j = op.idx;
      unite(col[par[j]],col[j]);
    } else {
      ans += get_now_color(col[op.idx]) + 1;
    }
  }
  cout << ans << endl;
}

signed main(void) {
  while(true) {
    cin >> N >> Q;
    if ( N == 0 && Q == 0) break;
    rep (i,N) G[i].clear();
    par[0] = 0;
    rep (i, N-1) {
      cin >> par[i + 1];
      par[i + 1]--;
      G[par[i+1]].push_back(i+1);
    }
    ops.resize(Q);
    rep (i,Q) {
      cin >> ops[i].com >> ops[i].idx;
      ops[i].idx--;
    }
    solve();
  }

}