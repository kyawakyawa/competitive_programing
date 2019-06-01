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

ll N;

ll game (ll Ai, ll Bi, ll Aj, ll Bj) {
  return (Ai + Bj - 1) / Bj - (Aj + Bi - 1) / Bi;
}
vector<ll> A,B,SA,SB;
int main(void) {
  cin >> N;
  rep(i,N) {
    ll a,b;
    cin >> a >> b;
    A.push_back(a);
    B.push_back(b);
  }
  SA=A;SB=B;

  ll s = N - 1;
  rrep(i, N) {
    if (i == 0) break;
    ll g = game(SA[i],SB[i],SA[i - 1],SB[i - 1]);
    if (g > 0) {
      swap(SA[i], SA[i - 1]);
      swap(SB[i], SB[i - 1]);
    } else {
      s = i - 1;
    }
    SA.pop_back();
    SB.pop_back();
  }

  ll c = 0;
  rep (i,N) {
    if (!game(SA[0], SB[0], A[i], B[i]))c++;
  }

  if (c < 2) cout << s + 1 << endl;
  else cout << -1 << endl;

  return 0;
}
