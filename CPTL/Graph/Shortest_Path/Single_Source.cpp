// dijkstra algorithm with priority queuec
// reference Programming Contest Challenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct edge {
  int to;
  T cost;
  edge (int to_,T cost_) : to(to_),cost(cost_) {}
};

template<typename T,template <typename ELEM> class C> struct Dijkstra {
  vector<vector<C<T>>> G;
  int V;
  T INF;
  using P = pair<T,int>;

  Dijkstra (int V_, T INF_ = 1e9) {
    init(V_,INF_);
  }

  void init(int V_,T INF_ = 1e9) {
    V = V_;
    INF = INF_;

    G.clear();
    G.resize(V);
  }

  void add_edge_directed(int from,int to,T cost) { // Directed Edge!!
    G[from].push_back(C<T>(to,cost));
  }

  void add_edge_non_directed(int from,int to,T cost){
    add_edge_directed(from,to,cost);
    add_edge_directed(to,from,cost);
  }

  void shortest_path(int s,T *d) {
    priority_queue<P,vector<P>,greater<P>> que;

    fill(d,d+V,INF);
    d[s] = 0; 
    que.push(P(0,s));

    while(!que.empty()) {
      P p = que.top(); que.pop();
      int v = p.second;

      if (d[v] < p.first) continue;

      for (auto e : G[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};

using ll = long long;

ll d[100010];

int main() {
  ll V,E,r;
  cin >> V >> E >> r;
  Dijkstra<ll,edge> dijkstra(V);
  rep(i,E) {
    ll s,t,d;
    cin >> s >> t >> d;
    dijkstra.add_edge_directed(s,t,d);
  }

  dijkstra.shortest_path(r,d);

  rep(i,V) 
    if(d[i] < 1e9)
      cout  << d[i] << endl;
    else 
      cout << "INF" << endl;
  return 0;
}
