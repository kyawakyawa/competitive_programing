// ford fulkerson algorithm
// refference Programming Contest Challenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct edge {
  using Type = T;
  int to;
  T cap;
  int rev_id;

  edge(int to_,T cap_,int rev_id_) : to(to_),cap(cap_),rev_id(rev_id_){};
};


template<class T> struct Graph_for_flow {
  vector<vector<T>> G;
  vector<bool> used;
  int V,E;

  Graph_for_flow(int V_) {
    init(V_);
  }

  void init(int V_) {
    V = V_;

    G.clear();
    G.resize(V);

    used.resize(V);

  }

  void add_edge(int from,int to,typename T::Type cap) {
    if(from < 0 || from >= V || to < 0 || to >= V ) {
      cerr << "warning" << endl;
    }

    G[from].push_back(T(to,cap,G[to].size()));
    G[to].push_back(T(from,0,G[from].size() - 1));
  }

  typename T::Type dfs(int v,int t,typename T::Type f) {
    if(v == t) return f;

    used[v] = true;

    for(auto &e : G[v]) {
      if(!used[e.to] && e.cap > 0) {
        typename T::Type d = dfs(e.to,t,min(f,e.cap));
        if(d > 0) {
          e.cap -= d;
          G[e.to][e.rev_id].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  typename T::Type max_flow(int s,int t) {
    typename T::Type flow = 0;
    for(;;) {
      fill(used.begin(),used.end(),false);
      typename T::Type f = dfs(s,t,1e9);
      if(f == 0)break;
      flow += f;
    }
    return flow;
  }
};
int main() {
  int V,E;

  cin >> V >> E;

  Graph_for_flow<edge<long long> > graph(V);

  rep(i,E) {
    long long u,v,c;

    cin >> u >> v >> c;

    graph.add_edge(u, v, c);

  }

  cout << graph.max_flow(0, V - 1) << endl;
  return 0;
}
