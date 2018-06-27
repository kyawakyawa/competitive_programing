#include<iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

ll fac[300000];
ll fac_inv[300000];
ll inv[300000];
const ll mod = 1e9+7;

void pre_compute(ll n) {
    fac[0] = fac[1] = 1;
    fac_inv[0] = fac_inv[1] = 1;
    inv[1] = 1;

    rep(i,n+1) {
        if(i < 2)continue;
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }

}

ll combination(ll n,ll k) {
    return fac[n] % mod * fac_inv[k] % mod * fac_inv[n - k] % mod;
}

ll n,k;
int main() {
    cin >> n >> k;

    pre_compute(n + k -1);

    cout << combination(n + k - 1,k) << endl;;
    return 0;

}