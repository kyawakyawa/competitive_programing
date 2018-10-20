// Kruskal法
// 最小全域木をのコストを求める。
// 参考 蟻本
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
#include<iostream>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

const int MAX_V = 100000;//頂点の最大数
const int MAX_E = 100000;//辺の最大数

ll par[MAX_V];
ll urank[MAX_E];

void init(ll n) {
  rep(i,n) {
    par[i] = i;
    urank[i] = 0;
  }
}

ll find(ll x) {
  if(par[x] == x) return x;

  return par[x] = find(par[x]);
}

void unite(ll x,ll y) {
  x = find(x);
  y = find(y);
  if(x == y)return;


  if(urank[x] < urank[y]) {
    par[x] = y;
  }else {
    par[y] = x;

    if(urank[x] == urank[y])urank[x]++;
  }
}

bool same(ll x,ll y) {
  return find(x) == find(y);
}


struct edge{ll u,v,cost;};

edge d[MAX_E];

bool comp(edge &a,edge &b) {
  return a.cost < b.cost;
}

ll V;//頂点の数
ll E;//辺の数

ll kruskal() {
  init(V);
  sort(d,d+E,comp);

  ll ret = 0;
  rep(i,E) {
    if(!same(d[i].u,d[i].v)) {
      ret += d[i].cost;
      unite(d[i].u,d[i].v);
    }
  }
  return ret;
}

int main() {
  cin >> V;
  cin >> E;

  rep(i,E) {
    cin >> d[i].u >> d[i].v >> d[i].cost;
  }

  cout << kruskal() << endl;
}

