#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int K;
double R,L,P,E,T;

double Search (double L, double R, int depth) {
  if (T - E < L && R < T + E) {
    return 1.0;
  }

  if (T < L - E || R + E < T) {
    return 0.0;
  }

  double H = (R + L) / 2.0;

  if (depth >= K) {
    return (abs(H - T) < E) ? 1.0 : 0.0;
  }

  if (T < H) {
    return P * Search(H, R, depth + 1) + (1.0 - P) * Search(L, H, depth + 1);
  }
  return (1.0 - P) * Search(H, R, depth + 1) +  P * Search(L, H, depth + 1);
}

void Solve(void) {
  printf("%.9f\n", Search(R, L, 0));
}

signed main(void) {
  cin >> K >> R >> L >> P >> E >> T;

  Solve();
}
