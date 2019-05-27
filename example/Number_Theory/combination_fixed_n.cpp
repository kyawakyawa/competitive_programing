// p(素数)を法とした時 nCkを計算 ただしnは固定値 k は10^7くらいまで可能
// 参考ページ  http://drken1215.hatenablog.com/entry/2018/06/08/210000
// O(N)


#include<iostream>

#define MAX_K 100000

using namespace std;

typedef long long ll;

ll combination_n[MAX_K + 1];//combination_n[i] := nCi

ll extend_gcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1;y = 0;
        return a;
    }
    ll r = a % b;
    ll d = extend_gcd(b,r,y,x);
    y -= (a / b) * x ;

    return d;
}

void precompute_for_combination(ll n,ll k,ll p) {
    combination_n[0] = 1;

    for(int i = 1;i <= k;i++) {
        ll x,y;
        extend_gcd(i,p,x,y);

        x %= p;

        if(x < 0) x = p + x;

        combination_n[i] = 
            combination_n[i - 1] * (n - i + 1) % p * x % p;
    }
}


int main() {
    ll n = 10;
    ll k = 10;
    ll p = 1e9 + 7;

    precompute_for_combination(n,k,p);

    printf("in modulo %lld\n\n",p);
    for(ll i = 0;i <= n;i++) {
        printf("%lldC%lld = %lld  \n",n,i,combination_n[i]);
    }
    return 0;
}