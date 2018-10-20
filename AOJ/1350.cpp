#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0;i < (n);i++)

typedef long long ll;

const int MAX_N = 500;
const int MAX_M = 100000;

ll par[MAX_N];
ll urank[MAX_N];
ll usize[MAX_N];
ll num;

void init(int n) {
  num = n;
  rep(i,n) {
    par[i] = i;
    urank[i] = 0;
    usize[i] = 1;
  }
}

ll find(ll x) {
  if(par[x] == x) {
    return x;
  }
  return par[x] = find(par[x]);
}

ll get_usize(ll x) {
  return usize[find(x)];
}

void unite(ll x,ll y) {
  x = find(x);
  y = find(y);
  if(x == y) return;

  ll s = usize[x] + usize[y];

  num--;
  if(urank[x] < urank[y]) {
    par[x] = y;
    usize[y] = s;
  } else {
    par[y] = x;
    usize[x] = s;
    if(urank[x] == urank[y]) urank[x]++;
  }
}

bool same(ll x,ll y) {
  return find(x) == find(y);
}

ll num_set() {
  return num;
}

struct edge {ll u,v,cost;};

bool comp(const edge &a,const edge &b) {
  return a.cost < b.cost;
}

ll N,M;

edge d[MAX_M];
bool notuse[MAX_M];
bool isNAB[MAX_M];


ll kruskal1 () {
  init(N);
  sort(d,d+M,comp);

  ll ret = 0;

  rep(i,M) {
    if(!same(d[i].u,d[i].v)) {
      ret += d[i].cost;
      isNAB[i] = true;
      unite(d[i].u,d[i].v);
    }
  }

  return ret;
}

ll kruskal2() {
  init(N);

  ll ret = 0;
  ll cou = 0;

  rep(i,M) {
    if(!same(d[i].u,d[i].v) && !notuse[i]) {
      ret += d[i].cost;
      unite(d[i].u,d[i].v);
      cou++;
    }
  }

  if(cou < N - 1) {
    return 1e9;
  }
  return ret;
}

int main() {
  cin >> N >> M;

  rep(i,M) {
    cin >> d[i].u >> d[i].v >> d[i].cost;
    d[i].u--;d[i].v--;
  }


  ll min_ = kruskal1();

  rep(i,M) {
    if(!isNAB[i]) {
      continue;
    }

    notuse[i] = true;
    ll min2_ = kruskal2();
    notuse[i] = false;

    if(min_ == min2_) {
      isNAB[i] = false;
    }
  }

  ll ans_a = 0,ans_b = 0;
  rep(i,M) {
    if(isNAB[i]) {
      ans_a++;
      ans_b += d[i].cost;
    }
  }

  cout << ans_a << " " << ans_b << endl;

  return 0;
}
