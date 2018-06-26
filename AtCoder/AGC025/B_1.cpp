#include<iostream>

#define MAX_N 500000

using namespace std;

typedef long long ll;

#define  rep(i,n) for(int i = 0;i < (n);i++)

ll factorial[MAX_N + 1];//factorial[n] := n! mod p
ll factorial_inverse[MAX_N+1];//factorial_inverse[n] = (n!)^-1 mod p

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

void precompute_for_combination(ll n,ll p) {//前計算 階乗や階乗の逆限を求めておく
    factorial[0] = factorial[1] = 1;
    for(int i = 2;i <= n;i++) {
        factorial[i] = factorial[i - 1] * i % p;
    }

    ll y;
    extend_gcd(factorial[n],p,factorial_inverse[n],y);

    factorial_inverse[n] %= p;
    if(factorial_inverse[n] < 0)factorial_inverse[n] = p - factorial_inverse[n];

    for(int i = n;i > 0;i--) {
        factorial_inverse[i - 1] = factorial_inverse[i] * i % p; 
    }
}

ll combination(ll n,ll k,ll p) {
    if(n < k || n < 0 || k < 0) return 0;//不正な値
    return factorial[n] % p * factorial_inverse[k] % p * factorial_inverse[n - k] % p;
}
ll N,A,B,K;
int main() {
    cin >> N >> A >> B >> K;
    ll p = 998244353;

    precompute_for_combination(N,p);

    ll ret = 0;
    rep(i,N+1) {
        ll a = i;
        ll b = K - a * A;
        if(b < 0 || b % B)continue;
        b  /= B;
        if(b > N)continue;
        (ret += combination(N,a,p) * combination(N,b,p) % p) %= p;
    }

    cout << ret << endl;
    
    return 0;
}