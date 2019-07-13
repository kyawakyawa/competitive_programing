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
#define int long long
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

template<typename T>
bool chmax(T &a, const T b) { if (a < b) { a = b; return true;} return false;}
template<typename T>
bool chmin(T &a, const T b) { if (a > b) { a = b; return true;} return false;}

int K;

int next (int n, int mod) {
  if (n % mod == mod - 1) {
    return n + mod;
  }
  return n + mod - 1 - (n % mod);
}

int S(int m) {
  int ret = 0;
  while(m > 0) {
    ret += m % 10;
    m /= 10;
  }
  return ret;
}

void solve() {
  int mod = 1;
  int n = 1;
  while(K > 0) {
    if (S(n) * mod >= n) {
      K--;
      cout << n << endl;
    } else {
      mod *= 10;
    }
    n = next(n, mod);
  }
}
signed main(void) {
  cin >> K;
  solve();
}