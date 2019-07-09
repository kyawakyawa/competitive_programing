#include <iostream>
#include <algorithm>

#define int long long
#define rep(i,n) for(int i=0;i <(n);i++)

using namespace std;

const int inf = 1e18;


int N;
int s[100000];

int calc(int A,int B) {
  //printf("A = %lld, B = %lld\n",A,B);
  int sum = 0;
  int x = 0;
  //while(x < N) {
  while(true) {
    int y = x + A;
    sum += s[y];
    if (y == N - 1) return sum;
    //printf("a y = %lld\n", y);

    y = y - B;
    sum += s[y];
    x = y;
    //printf("b y = %lld\n", y);
  }
  return -1;
}

int dp[100000];

bool in(int A) {
  return 0 < A && A < N;
}

signed main(void) {
  cin >> N;
  rep(i,N) {
    cin >> s[i]; 
  }

  rep(C, N) {
    if (C == 0) continue;
    dp[C] = (N - 1 - C > 0) ? 0 : -inf;
  }

  int ans = 0;
  for (int k = 1; k < N; k++) {
    for (int C = 1;k * C < N ;C++) {
      int A = N - 1 - k * C;
      int B = A - C;
      if (!in(A) || !in(B)) continue;
      //if (B % C == 0 && N - 1 - A - B > 0) continue;
      if ((N - 1) % C == 0 && N - 1 <= 2 * k * C) continue;

      dp[C] += s[N - 1 - k * C] + s[k * C];
      ans = max(dp[C], ans);
    }
  }
  cout << ans << endl;
  return 0;
}
