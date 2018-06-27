#include<iostream>

using namespace std;

#define rep(i,n) for(ll i=0;i<(n);i++) 

typedef long long ll;

ll extend_gcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll r = a % b;

    ll d = extend_gcd(b,r,y,x);

    y -= (a / b) * x;

    return d;
}

ll fac[1000];
ll fac_inv[1000];
const ll p = 1e9+7;
void pre_compute(ll n) {
    fac[0] = fac[1] = 1;
    fac_inv[0] = fac_inv[1] = 1;

    rep(i,n+1) {
        if(i < 2)continue;
        fac[i] = fac[i - 1] * i % p;
    }

    ll  y;
    extend_gcd(fac[n],p,fac_inv[n],y);
    fac_inv[n] %= p;
    if(fac_inv[n] < 0) fac_inv[n] += p;

    for(int i = n;i > 2;i--){
        fac_inv[i - 1] = fac_inv[i] * i % p;
    }
}

ll combination(ll n,ll k) {
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n] * fac_inv[k] % p * fac_inv[n - k] % p;
}

ll R,C,X,Y,D,L;

int main() {
    cin >> R >> C >> X >> Y >> D >> L;


    pre_compute(X * Y);

    if(X * Y == D + L) {
        ll ans = combination(X*Y,D);
        ans *= (R - X + 1) * (C - Y + 1) % p;
        ans %= p;
        cout << ans << endl;
        return 0;
    }

    ll ans = 0;
    for(ll i = -1;i < 1;i++) {
        for(ll j = -1;j < 1;j++) {
            for(ll k = -1;k < 1;k++) {
                for(ll l = -1;l < 1;l++) {
                    ll cou = 0;
                    if(i == -1)cou++;
                    if(j == -1)cou++;
                    if(k == -1)cou++;
                    if(l == -1)cou++;

                    if(cou % 2 == 0) {
                        ans += combination((X + i + j) * (Y + k + l),D + L) * combination(D+L,L) % p;
                    }else {
                        ans -= combination((X + i + j) * (Y + k + l),D + L) * combination(D+L,L) % p;
                    }
                    ans %= p;
                    if(ans < 0)ans += p;
                }
            }
        }
    }

    ans *= (R - X + 1) * (C - Y + 1);
    ans %= p;
    if(ans < 0)ans+=p;
    cout << ans << endl;
    return 0;
}