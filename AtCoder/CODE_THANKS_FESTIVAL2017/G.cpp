#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,m;
vector<int> G[40];
int g[40][40];
bool dp1[1<<20];
int dp2[1<<20];
int dp3[1<<20];

int GetOneElem(int S,int n) {
  if (S==0) return -1;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (S>>i & 1) {
      break;
    }
  }
  return i;
}

int BitCount(int data) {
  int ret = 0;
  for (; data; data &= data - 1) ret++;
  return ret;
}
signed main(void) {
  cin >> n >> m;
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
    g[a][b] = g[b][a] = true;
  }
  int n2 = n / 2;
  int s1 = n2;
  int s2 = n - n2;

  rep(S,1<<s1) {
    vector<int> vs;
    rep(i,s1) {
      if(S>>i & 1) vs.push_back(i);
    }
    bool flag = true;
    rep(i,vs.size()) {
      for(int j = i + 1;j < vs.size(); j++) {
        if (g[vs[i]][vs[j]]) {
          flag = false;
        }
      }
    }
    dp1[S] = flag;
  }

  dp2[0] = (1ll << s2) - 1;
  rep(S,1ll<<s1) {
    if (S == 0) continue;
    int i = GetOneElem(S, s1);
    int S2 = (S & ~(1ll<<i));

    int V2 = (1ll << s2) - 1;
    for (auto v : G[i]) {
      v -= s1;
      if (v >= 0) V2 = (V2 & ~(1ll<<v));
    }
    dp2[S] = (dp2[S2] & V2);
  }

  rep(U,1<<s2) {
    vector<int> vs;
    rep(i,s2) {
      if(U>>i & 1) vs.push_back(i+s1);
    }
    bool flag = true;
    rep(i,vs.size()) {
      for(int j = i + 1;j < vs.size(); j++) {
        if (g[vs[i]][vs[j]]) {
          flag = false;
        }
      }
    }
    if (flag) dp3[U] = BitCount(U);
    else dp3[U] = 0;
  }
  rep(U, 1ll<<s2) {
    if (U==0) continue;
    rep(i,s2) {
      if (!(U>>i & 1)) continue;
      int U2 = (U & ~(1ll<<i));
      dp3[U] = max(dp3[U],dp3[U2]);
    }
  }

  int ans = 0;
  rep(S, 1ll<<s1) {
    if (!dp1[S]) continue;

    ans = max(ans, dp3[dp2[S]] + BitCount(S));
  }
  cout << ans << endl;
  return 0;
}