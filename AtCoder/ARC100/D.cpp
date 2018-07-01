#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i =0;i <(n);i++) 
#define FOR(i,a,b) for(int i=a;i<(b);i++)

ll n,a[300000];

ll calc(ll m,ll s,ll t) {
    ll M = a[t - 1] - a[m - 1];
    ll ma = a[m - 1] - a[s - 1];
    return abs(M - ma);
}

ll bs(ll s,ll t) {
    ll l = s + 1,r = t;

    while(r - l > 1) {
        ll mid = (r + l) / 2;
        if(calc(mid + 1,s,t) - calc(mid,s,t) > 0) {
            r = mid;
        }else {
            l = mid;
        }
    }
    if(calc(r,s,t) < calc(l,s,t)) {
        //cout << "a" << endl;
        return r;
    }
    //cerr << calc(r,s,t) << " " << calc(l,s,t) << endl;
    return l;;
}

int main() {
    cin >> n;
    rep(i,n) cin >> a[i+1];

    rep(i,n)a[i+1] += a[i];

    ll ans = 100000000000000;
    for(int i = 3;i < n;i++) {
        ll c = bs(1,i);
        ll d = bs(i,n+1);

        cerr << c << " " << i << " " << d << endl;
        
        ll s[4];
        s[0] = a[c - 1] - a[0];
        s[1] = a[i-1] - a[c - 1];
        s[2] = a[d - 1] - a[i - 1];
        s[3] = a[n] - a[d - 1];

        ll maxi = 0;
        rep(i,4) {
            FOR(j,i+1,4) {
                maxi = max(maxi,abs(s[j] - s[i]));
            }
        }
        ans = min(maxi,ans);
    }
    cout << ans << endl;

    return 0;
}