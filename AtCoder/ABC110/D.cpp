#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define MAX_N 200000

ll mod = 1000000007;

ll factorial[MAX_N + 1];
ll factorial_inverse[MAX_N + 1];

ll extgcd(ll a,ll b,ll &x,ll & y) {
    if(b == 0) {
        x = 1,y = 0;
        return a;
    }

    ll d = extgcd(b,a % b,y,x);
    y -= (a / b) * x;
    return d;
}

void precom(ll N) {
    factorial[0] = factorial_inverse[0] = 1;

    for(ll i = 1;i <= N;i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    } 
    ll y;
    extgcd(factorial[N],mod,factorial_inverse[N],y);

    for(ll i = N - 1;i > 0;i--){
        factorial_inverse[i] = factorial_inverse[i + 1] * (i + 1) % mod;
    }
}

ll C(ll n,ll k) {
    return factorial[n] * factorial_inverse[k] % mod * factorial_inverse[n - k] % mod;
}

vector<ll> ps;
vector<ll> e;

void div(ll n) {
    for(int i = 2;i <= sqrt(n);i++) {
        if(n % i == 0) {
            div(i);
            div(n / i);
            return;
        }
    }
    ps.pb(n);
    return;
}
ll n,m;
int main(){
    cin >> n >> m;
    if(m == 1) {
        cout << 1 << endl;
        return 0;
    }
    div(m);

    sort(ps.begin(),ps.end());

    ll c = 0;
    rep(i,ps.size()) {
        c++;
        if(i == ps.size() - 1 || ps[i] != ps[i + 1]) {
            e.pb(c);
            c = 0;
        }
    }

    precom(200000);

    ll ans = 1;

    for(auto v : e) {
        (ans *= C(n + v - 1,v)) %= mod;
    }

    cout << ans << endl;
    return 0;
}

