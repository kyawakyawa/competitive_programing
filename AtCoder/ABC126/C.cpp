#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define rep(i,n) for(int i =0;i<(n);i++)


long N,K;
int main(void) {

  scanf("%ld%ld",&N,&K);

  double ans = 0;
  for (int i = 1;i <= N;i++) {
    double p = 1.0 / 2.f;

    int c = 0;

    int j = i;

    while(j < K) {
      j *= 2;
      c++;
    }

    ans += 1.0 / N * pow(p,c);
  }

  printf("%.17f\n", ans);

  return 0;
}