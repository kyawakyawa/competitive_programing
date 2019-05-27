#include <bits/stdc++.h>

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

template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;}return false;}

// --!!!!ここからコピペする!!!!--

template<typename T> struct Edge {
  int to;
  Edge(int to_) : to(to_) {}
};

template<typename T,template <typename ELEM> class EDGE> struct AdListGraph {
  vector<vector<EDGE<T>>> G;
  vector<bool> used;
  vector<bool> is_ancetor;
  int V;//0,...,|V|-1

  AdListGraph (int V_) {
    Init(V_);
  }

  void Init(int V_) {
    V = V_;

    G.clear();
    G.resize(V);
  }

  // https://faithandbrave.hateblo.jp/entry/20080310/1205149207
  template <typename FROM, class... Args>
  void AddEdge(FROM from, Args&&... arg) {
    G[from].emplace_back(arg...);
  }

  bool DFSForTopologicalSort (int i, vector<int>& sorted) {
    if (is_ancetor[i]) return false;
    if (used[i]) return true;

    used[i] = true;
    is_ancetor[i] = true;

    for(const auto& v : G[i]) {
      if(!DFSForTopologicalSort(v.to, sorted)) return false;
    }

    is_ancetor[i] = false;
    sorted.emplace_back(i);//dfsの帰りがけの順

    return true;
  }

  template<typename ID_TYPE>
  bool TopologicalSort (vector<ID_TYPE>& sorted) { // 成功ならtrue 失敗(DAG出ない)ならfalseを返す
    used.clear();
    used.resize(V,false);
    is_ancetor.clear();
    is_ancetor.resize(V, false);

    sorted.clear();

    rep (i,V) {
      if(!DFSForTopologicalSort(i, sorted)) {
        return false;
      }
    }

    reverse(sorted.begin(),sorted.end());

    return true;
  }

};

using ll = long long;

int dp[100010];

int main() {
  ll V,E;
  cin >> V >> E;
  AdListGraph<ll, Edge> G(V);
  AdListGraph<ll, Edge> rG(V);
  rep(i,E) {
    ll s,t;
    cin >> s >> t;
    s--;t--;
    G.AddEdge(s, t);
    rG.AddEdge(t, s);
  }

  vector<int> sorted;

  G.TopologicalSort(sorted);

  for (auto v : sorted) {
     for (auto u : rG.G[v]) {
       chmax(dp[v],dp[u.to] + 1);
     }
  }

  int ans = 0;

  rep(i,V) {
    chmax(ans, dp[i]);
  }

  cout << ans << endl;

  return 0;
}
