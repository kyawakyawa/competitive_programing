#include <iostream>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int N,C[100][100];
signed main(void) {
  cin >> N;
  rep(i,N)rep(j,N)cin >> C[i][j];
  int ans = 0;
  rep(i,N) {
    for (int j = i + 1; j < N; j++) {
      ans += min(C[i][j], C[j][i]); 
    }
  }
  cout << ans << endl;
  return 0;
}