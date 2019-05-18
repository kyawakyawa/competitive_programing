#include <stdio.h>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
constexpr long long INF = 1000000000000000;

long long N;
long long h[100000];
long long min_cost[100000];


int main(void) {
  scanf("%lld", &N);

  rep(i,N) scanf("%lld",h+i);
  rep(i,N-1) min_cost[i+1] = INF;

  rep(i,N) {
    min_cost[i + 1] = min(min_cost[i + 1], min_cost[i] + abs(h[i + 1] - h[i]));
    min_cost[i + 2] = min(min_cost[i + 2], min_cost[i] + abs(h[i + 2] - h[i]));
  }

  printf("%lld\n", min_cost[N - 1]);

  return 0;
}