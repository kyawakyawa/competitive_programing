#include<iostream>

using namespace std;
using ll = long long;

signed main() {
  ll n,m,a;
  cin >> n >> m >> a;

  cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
  return 0;
}
