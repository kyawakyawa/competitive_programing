// bellman ford algorithm
// reference Programming Contest Challenge Book Second Edition
//verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct edge {
  int from,to;
  T cost;

  edge(int from_,int to_,T cost_) : from(from_),to(to_),cost(cost_){};
};

template<typename T,template <typename ELEM> class C> struct Bellman_Ford {
  vector<C<T>> edges;
  int V;//0,...,|V|-1
  T INF;

  Bellman_Ford (int V_,T INF_ = 1e9) {
    init(V_,INF_);
  }

  void init(int V_,T INF_ = 1e9) {
    V = V_;
    INF = INF_;

    edges.clear();
  }

  void add_edge(int from,int to,T cost) {
    //edges.push_back(from,to,cost);
    edges.push_back(C<T>(from,to,cost));
  }

  bool shortest_path(int s,T *d) {
    fill(d,d+V,INF);
    d[s] = 0;

    int E = edges.size();

    rep(i,V) {
      bool update = false;
      rep(j,E) {
        auto e = edges[j];
        if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
          d[e.to] = d[e.from] + e.cost;
          update = true;
        }
      }
      if( !update) break;
      if(update && i == V - 1) {
        return false;;
      }
    }
    return true;
  }

};

using ll = long long;
ll d[1010];

int main() {
  ll V,E,r;
  cin >> V >> E >> r;
  Bellman_Ford<ll,edge> bf(V);
  rep(i,E) {
    ll s,t,dd;
    cin >> s >> t >> dd;
    bf.add_edge(s,t,dd);
  }

  if(bf.shortest_path(r,d)) {
    rep(i,V) {
      if(d[i] < 1e9)
        cout << d[i] << endl;
      else 
        cout << "INF" << endl;
    }
  }else {
    cout << "NEGATIVE CYCLE" << endl;
  }

  return 0;
}
