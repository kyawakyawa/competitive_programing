#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
ll INF = 1e9;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)

ll n,ma,mb;

vector<ll> a,b,c;
ll dp[50][410][410];

ll gcd(ll a,ll b) {
  if (b == 0) 
    return a;

  return gcd(b,a % b);
}

int main(){
  cin >> n >> ma >> mb;

  a.resize(n);b.resize(n);c.resize(n);

  rep(i,n)cin >> a[i] >> b[i] >> c[i];

  ll sa = 0,sb = 0;

  rep (i,n) {
    sa += a[i];
    sb += b[i];
  }

  rep (i,sa+1) {
    rep (j,sb+1) {
      dp[n][i][j] = INF;
    }
  }
  dp[n][0][0] = 0;

  rrep(i,n) {
    rep(j,sa+1) {
      rep (k,sb+1) {
        if (j - a[i] >= 0 && k - b[i] >=0)
          dp[i][j][k] = min(dp[i+1][j][k],dp[i+1][j - a[i]][k - b[i]] + c[i]); 
        else 
          dp[i][j][k] = dp[i+1][j][k];
      }
    }
  }

  ll ans = INF;

  for (int i = 1;i <= sa;i++) {
    for (int j = 1;j <= sb;j++) {

      ll d = gcd(i,j);

      ll aa = i / d;
      ll bb = j / d;
     
      if(aa == ma && bb == mb) {
        ans = min(ans,dp[0][i][j]);
      }
    }
  }

  if (ans < INF)
    cout << ans << endl;
  else 
    cout << -1 << endl;
  
}

