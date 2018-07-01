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
    cerr << s << " " << calc(l,s,t) << " " << t << endl;
    //cerr << calc(l-1,s,t) << " " << calc(l,s,t) << endl;
    if(calc(l,s,t) < calc(l - 1,s,t)) {
        return l;
    }
    return l - 1;;
}

int main() {
    cin >> n;
    rep(i,n) cin >> a[i+1];

    rep(i,n)a[i+1] += a[i];
    rep(i,n+1) cerr << a[i] << " ";
    cerr << endl;

    cout << bs(3,6) << endl;;

    return 0;
}