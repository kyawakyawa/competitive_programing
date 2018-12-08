// checking graph cycle with dfs algorithm
// reference Programming Contest Challenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_4_A

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct edge {
  int to;

  edge(int to_) : to(to_) {}
};

template<typename T,template <typename ELEM> class C> struct Check_Cycle {
  vector<vector<C<T>>> G;
  vector<bool> used;
  int V;//0,...,|V|-1

  Check_Cycle (int V_) {
    init(V_);
  }

  void init(int V_) {
    V = V_;

    G.clear();
    G.resize(V);
  }

  void add_edge(int from,int to) {
    G[from].push_back(C<T>(to));
  }

  bool dfs (int i,set<int> pars) {
    pars.insert(i);
    used[i] = true;

    rep(j,(int)G[i].size()) {
      if (!used[G[i][j].to]) {
        if(dfs(G[i][j].to,pars)) {
          return true;
        }
      } else {
        if (pars.find(G[i][j].to) != pars.end())  {
          return true;
        }
      }
    }

    pars.erase(i);
    return false;
  }

  bool check_cycle () {
    used.clear();
    used.resize(V,false);

    rep (i,V) {
      if (!used[i] && dfs(i,set<int>())) {
        return true;
      }
    }

    return false;
  }

};

using ll = long long;

int main() {
  ll V,E;
  cin >> V >> E;
  Check_Cycle<ll,edge> cc(V);
  rep(i,E) {
    ll s,t;
    cin >> s >> t;
    cc.add_edge(s,t);
  }

  cout << cc.check_cycle() << endl;

  return 0;
}
