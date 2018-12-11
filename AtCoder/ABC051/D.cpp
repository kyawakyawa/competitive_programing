#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define rep(i,n) for (int i=0;i<(n);i++)

#define INF (1000000000)

int main(){
  vector<vector<ll>> G;

  int n,m;
  cin >> n >> m;

  G.resize(n,vector<ll>(n,INF));

  rep(i,n)G[i][i] = 0;

  rep(i,m) {
    ll a,b,c;

    cin >> a >> b >> c;
    a--;b--;

    G[a][b] = G[b][a] = c;
  }

  vector<vector<ll>> G2 = G;

  rep(k,n) {
    rep(i,n) {
      rep( j,n) {
        G2[i][j] =  min(G2[i][j],G2[i][k] + G2[k][j]);
      }
    }
  }

  ll ans = 0;

  rep(i,n) {
    for (int j=i+1;j<n;j++) {
      if (G[i][j] < INF && G[i][j] > G2[i][j])
        ans++;
    }
  }
  cout << ans << endl;
}

