// p(素数で無くて良い)を法とした時 nCkを計算 
// 参考ページ  http://drken1215.hatenablog.com/entry/2018/06/08/210000
// O(N^2)


#include<iostream>

using namespace std;

typedef long long ll;

#define MAX_N 3000
#define MAX_K MAX_N

ll combination[MAX_N][MAX_K];

void precompute_for_combination(ll n,ll p) {//前計算 階乗や階乗の逆限を求めておく
  for(int i = 0;i <= n;i++) {
    combination[0][i] = (i == 0);
  }

  for(int i = 1;i <= n;i++) {
    combination[i][0] = 1;
    for(int j = 1;j <= n;j++) {
      combination[i][j] = 
        (combination[i - 1][j] + combination[i - 1][j - 1])  % p;
    }
  }
}

int main() {
  ll n = 10;
  ll p = 1e9 + 6;

  precompute_for_combination(n,p);

  printf("in modulo %lld\n\n",p);
  for(ll i = 0;i <= n;i++) {
    for(ll k = 0;k <= i;k++) {
      printf("%lldC%lld = %lld  ",i,k,combination[i][k]);
    }
    printf("\n");
  }
  return 0;
}
