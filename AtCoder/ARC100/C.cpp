#include<iostream>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i =0;i <(n);i++) 
#define FOR(i,a,b) for(int i=a;i<(b);i++)

ll n,a[300000];

ll calc(ll b) {
    ll ret = 0;
    rep(i,n) {
        ret += abs(a[i] - (b + i + 1));
    }
    return ret;
}

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];

    ll l = -2000000010,r = 2000000010;

    while(r - l > 1) {
        int mid = (l + r) / 2;
        //(calc(mid) - calc(mid - 1) > 0) ? l : r = mid;
        if(calc(mid) - calc(mid-1) > 0) r = mid;
        else l = mid;
        //cerr << l << " " << r << endl;
    }
    cout << calc(l) << endl;
    return 0;
}