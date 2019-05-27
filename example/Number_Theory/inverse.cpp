// p(素数)を法とした時 i の 逆元(inverse[i])  を計算する。
// 参考ページ  http://drken1215.hatenablog.com/entry/2018/06/08/210000
// O(N)


#include<iostream>

#define MAX_N 100000

using namespace std;

typedef long long ll;

ll inverse[MAX_N + 1];

void calc_inverse(ll n,ll p) {//p(素数)を法とした時の1〜nの逆元を求める
    inverse[1] = 1;

    for(int i = 2;i <= MAX_N;i++) {
        inverse[i] = p - inverse[p % i] * (p / i) % p;
    }
}

int main() {
    ll n = 100;
    ll p = 1e9 + 7;

    calc_inverse(n,p);

    for(ll i = 1;i < n;i++) {
        printf("%lld (%lld * %lld = %lld)\n",inverse[i],i,inverse[i],i * inverse[i] % p);
    }
    return 0;
}