// Warshall-Floyd  algorithm 
// reference Programming Contest Challenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct Warshall_Froyd {
  vector<vector<T>> G;
  int V;
  T INF;

  Warshall_Froyd(int V_,T INF_ = 1e9) {
    init(V_,INF_);
  }

  void init (int V_,T INF_ = 1e9) {
    V = V_;
    INF = INF_;

    G.resize(V,vector<T>(V,INF_));
    rep(i,V)G[i][i] = 0;
  }

  void add_edge_directed(int from,int to,T cost) {
    G[from][to] = cost;
  }

  void add_edge_non_directed(int from,int to,T cost) {
    G[from][to] = G[to][from] = cost;
  }

  vector<vector<T>> shortest_path() {
    rep(k,V) {
      rep(i,V) {
        rep(j,V) {
          G[i][j] = min(G[i][k] + G[k][j],G[i][j]);
        }
      }
    }

    return G;
  }
};

using ll = long long;


int main() {
  int V,E;
  cin >> V >> E;
  ll INF = 1e18;
  Warshall_Froyd<ll> wf(V,INF);

  rep(i,E) {
    ll s,t,d;
    cin >> s >> t >> d;
    wf.add_edge_directed(s,t,d);
  }

  vector<vector<ll>> d = wf.shortest_path();

  rep(i,V) {
    if(d[i][i] != 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  rep(i,V) {
    rep(j,V) {
      if(d[i][j] < INF / 2)cout << d[i][j];//負の辺があるとINFより小さくなることがある
      else cout << "INF";
      cout << ((j < V - 1) ? " " : "");
    }
    cout << endl;
  }
  return 0;
}
