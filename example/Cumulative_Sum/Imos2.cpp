//2次元いもす法の基本的な問題
#include<iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i=0;i<(n);i++)

ll N;

ll c[1010][1010];

int main() {
    cin >> N;

    rep(i,N) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;//[x1,x2) [y1,y2)

        c[y1][x1]++;
        c[y1][x2]--;
        c[y2][x1]--;
        c[y2][x2]++;
    }

    rep(i,1001) {
        rep(j,1000) {
            c[i][j + 1] += c[i][j];
        }
    }
    rep(j,1001) {
        rep(i,1000) {
            c[i + 1][j] += c[i][j];
        }
    }

    ll ans = 0;

    rep(i,1001)rep(j,1001) ans = max(ans,c[i][j]);

    cout << ans << endl;
    return 0;
}