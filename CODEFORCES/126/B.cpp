#include<iostream>
#include<vector>
#include<numeric>
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

int main(){
  ll n;
  vector<ll> p;
  cin >> n;
  p.resize(n);
  rep(i,n)cin >> p[i];
  ll sum = accumulate(p.begin(),p.end(),0);

  printf("%.10f\n",sum / (double)n);
  return 0;

}

