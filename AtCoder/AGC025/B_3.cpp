#include<iostream>

#define MAX_K 500000
#define rep(i,n) for(int i=0;i<(n);i++)

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


ll N,A,B,K;
int main() {
    cin >> N >> A >> B >> K;
    ll p = 998244353;

    precompute_for_combination(N,N,p);

    ll ret = 0;
    rep(i,N+1) {
        ll a = i;
        ll b = K - a * A;
        if(b < 0 || b % B)continue;
        b  /= B;
        if(b > N)continue;
        (ret += combination_n[a] * combination_n[b] % p) %= p;
    }

    cout << ret << endl;
    
    return 0;
}