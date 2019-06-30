#include <iostream>
#define int long long
using namespace std;

int N,k;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

#if 0
signed main(void) {
  cin >> N >> k;

  int x = 0;
  N--;
  while (true) {
    int i = ceil(x + 1, k - 1);
    int z = i * k - 1 - i;

    int c = ceil(z - x + 1, i);
    if (c >= N) {
      cout << x + N * i << endl;
      break;
    }
    x = c * i + x;
    N -= c;
  }
  return 0;
}
 
# else 
signed main(void) {
  cin >> N >> k;
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int add = ans / (k - 1) + 1;
    ans += add;
  }
  cout << ans << endl;
  return 0;
}
#endif