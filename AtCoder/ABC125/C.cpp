#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>

using  ll = long long;
using ull = unsigned long long;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};
constexpr ll kINF = 1152921504606846976;//2^60
constexpr double kEPS = 1e-6;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define rep(i,n) REP(i,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep(i,n) RREP(i,n)
#define mp make_pair
#define fi first
#define sc second

ll N,A[100000];

ll gcd (ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main(void) {
  cin >> N;
  rep (i,N) cin >> A[i];
  
  ll ans = A[0];
  ll g   = A[0];

  rep (i,N) {
    if (i < 1) continue;
    ans = max(gcd(ans, A[i]), g);
    g = gcd(g, A[i]);
  }

  ll g2 = A[1];
  rep(i,N-1) g2 = gcd(g2, A[i+1]);

  ans = max(ans, g2);

  cout << ans << endl;

  return 0;
}