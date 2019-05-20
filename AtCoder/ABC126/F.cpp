#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<complex>

using  ll = long long;
using ull = unsigned long long;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define rep(i,n) REP(i,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep(i,n) RREP(i,n)
#define mp make_pair
#define fi first
#define sc second

ll M,K;
bool used[1 << 20];
int main(){
  cin >> M >> K;
  ll N = (1 << M);

  if (K >= N) {
    printf("-1\n");
    return 0;
  }

  if (M == 1) {
    if (K >= 1)
      printf("-1\n");
    else
      printf("0 0 1 1\n");
    return 0;
  } 

  if (K == 0) {
    rep (i,N) {
      printf("%d %d ", i, i);
    }
    printf("\n");
    return 0;
  }

  ll p = 0;
  rep(i,N/4) {
    while(used[p])p++;
    ll a = p;
    ll q = a + 1;
    while(used[q] || (a ^ K) == q)q++;
    ll b = q;

    used[a] = used[b] = used[a ^ K] = used[b ^ K] = true;
    
    printf("%lld %lld %lld %lld %lld %lld %lld %lld ", a, a ^ K, b, b ^ K, a ^ K, a, b ^ K, b);
  }
  printf("\n");
  return 0;
}
