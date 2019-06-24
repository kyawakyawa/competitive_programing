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

ll l[100000],r[100000];
int main(void) {
  cin >> N;
  rep (i,N) cin >> A[i];

  l[0] = A[0];
  rep (i,N-1)l[i + 1] = gcd(l[i], A[i + 1]);
  r[N-1] = A[N-1];
  rrep (i,N-1)r[i] = gcd(r[i+1], A[i]);

  ll ans = 1;

  rep (i,N) {
    ll l2 = (i > 0 ? l[i - 1] : 0);
    ll r2 = (i < N - 1 ? r[i + 1] : 0);
    ans = max(ans, gcd(l2, r2));
  }

  cout << ans << endl;

  return 0;
}