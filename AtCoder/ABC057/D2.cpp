//解説をもとに無駄を減らした回答
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
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)

ll C[51][51];
ll N,A,B;
vector<ll> v;

void calc_C() {
  C[0][0] = 1;

  for (int i = 1;i <= 50;i++) {
    C[i][0] = 1;
    for (int j = 1;j <= 50;j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

void solve() {
  calc_C();
  sort(v.begin(),v.end(),greater<ll>());
  ll maxi = 0;

  rep(i,N) maxi = max(v[i],maxi);

  ll nmax = 0;
  rep(i,N) nmax += (v[i] == maxi);

  ll kumi = 0;
  if (nmax < A) {
    ll x = 0;
    rep (i,N)if(v[i] == v[A - 1])x++;
    ll y = 0;
    rep (i,A)if(v[i] == v[A - 1])y++;

    kumi += C[x][y];
  } else {
    for (int i = A;i <= B;i++) { // nmax < i の時はcombinationが0になるのでok
      kumi += C[nmax][i];
    }
  }

  double kati = 0.0;

  rep(i,A)kati += v[i];

  kati /= A;

  printf("%.10f\n%lld\n",kati,kumi);
}

int main(){
  cin >> N >> A >> B;

  v.resize(N);
  rep(i,N) {
    cin >> v[i];
  }
  solve();
  return 0;
}

