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
    for(int b = -10; b < 11;b++) 
        cout << calc(b) << endl;
    return 0;
}