// p(素数)を法とした時 nCkを計算 1〜max n の逆元も求める。 
// 参考ページ  http://drken1215.hatenablog.com/entry/2018/06/08/210000
// O(N)


#include<iostream>

#define MAX_N 100000

using namespace std;

typedef long long ll;

ll factorial[MAX_N + 1];//factorial[n] := n! mod p
ll factorial_inverse[MAX_N+1];//factorial_inverse[n] = (n!)^-1 mod p
ll inverse[MAX_N + 1];//inverse[n] := 1 / n mod p

void precompute_for_combination(ll n,ll p) {//前計算 階乗や階乗の逆限を求めておく
    factorial[0] = factorial[1] = 1;
    factorial_inverse[0] = factorial_inverse[1] = 1;
    inverse[1] = 1;
    for(int i = 2;i <= n;i++) {
        factorial[i] = factorial[i - 1] * i % p;
        inverse[i] = p - inverse[p % i] * (p / i) % p;
        factorial_inverse[i] = factorial_inverse[i - 1] * inverse[i] % p;
    }
}

ll combination(ll n,ll k,ll p) {
    if(n < k || n < 0 || k < 0) return 0;//不正な値
    return factorial[n] % p * factorial_inverse[k] % p * factorial_inverse[n - k] % p;
}

int main() {
    ll n = 10;
    ll p = 1e9 + 7;

    precompute_for_combination(n,p);

    printf("in modulo %lld\n\n",p);
    for(ll i = 0;i <= n;i++) {
        for(ll k = 0;k <= i;k++) {
            printf("%lldC%lld = %lld  ",i,k,combination(i,k,p));
        }
        printf("\n");
    }
    return 0;
}