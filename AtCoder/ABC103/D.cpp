#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

using P = pair<int,int>;
int n,m;

vector<int> a,b;
int calc(vector<int>& s,vector<int>& t) {
  vector<P> ps;
  rep(i,m){
    ps.push_back(P(b[i]-1,a[i]));
  }

  sort(ps.begin(), ps.end());

  int ret = 0;
  int nowt = 0;
  for (auto p : ps) {
    if (nowt < p.second) {
      ret++;
      nowt = p.first;
    }
  }
  return ret;
}

void solve() {
  int x = calc(a,b);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int y = 100000;//calc(a,b);
  cout << min(x,y) << endl;
}

signed main(void) {
  cin >> n >> m;
  a.resize(m);b.resize(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
  }
  solve();
  return 0;
}
