#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct edge {
  int to;
  T cap;
  int rev_id;

  edge(int to_,T cap_,int rev_id_) : to(to_),cap(cap_),rev_id(rev_id_){};
};


template<typename T,template <typename ELEM> class C> struct Graph_for_flow {
  vector<vector<C<T>>> G;
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

  void add_edge(int from,int to,T cap) {
    if(from < 0 || from >= V || to < 0 || to >= V ) {
      cerr << "warning" << endl;
    }

    G[from].push_back(C<T>(to,cap,G[to].size()));
    G[to].push_back(C<T>(from,0,G[from].size() - 1));
  }

  T dfs(int v,int t,T f) {
    if(v == t) return f;

    used[v] = true;

    for(auto &e : G[v]) {
      if(!used[e.to] && e.cap > 0) {
        T d = dfs(e.to,t,min(f,e.cap));
        if(d > 0) {
          e.cap -= d;
          G[e.to][e.rev_id].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  T max_flow(int s,int t) {
    T flow = 0;
    for(;;) {
      fill(used.begin(),used.end(),false);
      T f = dfs(s,t,1e9);
      if(f == 0)break;
      flow += f;
    }
    return flow;
  }
};

using ll = long long;
ll N;
vector<string> S;

int main() {
  cin >> N;

  S.resize(N);

  rep(i,N) cin >> S[i];


  vector<char> ans;

  rep(i,26) {
    Graph_for_flow<ll,edge> graph(28);
    int deg_out = 0,deg_in = 0;
    int s = 26,t = 27;
    rep(j,N) {
      char u = S[j].front() - 'a';
      char v = S[j].back() - 'a';

      if(u == i) {u = s;deg_out++;}
      if(v == i) {v = t;deg_in++;}

      graph.add_edge(u,v,1);
    }

    ll flow = graph.max_flow(s,t);

    if(flow == deg_out && deg_in > 0)ans.push_back(i + 'a');
  }

  for(auto v : ans) {
    cout << v << endl;
  }
  return 0;
}

