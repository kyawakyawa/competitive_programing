#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

ll N;
vector<ll> x,y;
ll x1[2000],y1[2000],x2[2000],y2[2000];

ll c[4020][4020];//x1,x2があるのでNの倍必要

int main() {
    cin >> N;
    rep(i,N) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];//[x1,x2) [y1,y2)

        x.push_back(x1[i]);x.push_back(x2[i]);
        y.push_back(y1[i]);y.push_back(y2[i]);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());

    rep(i,N) {
        ll ix1 = lower_bound(x.begin(),x.end(),x1[i]) - x.begin();
        ll ix2 = lower_bound(x.begin(),x.end(),x2[i]) - x.begin();
        ll iy1 = lower_bound(y.begin(),y.end(),y1[i]) - y.begin();
        ll iy2 = lower_bound(y.begin(),y.end(),y2[i]) - y.begin();

        c[iy1][ix1]++;
        c[iy1][ix2]--;
        c[iy2][ix1]--;
        c[iy2][ix2]++;
    }

    rep(i,y.size()) {
        rep(j,x.size() - 1) {
            c[i][j + 1] += c[i][j]; 
        }
    }

    rep(j,x.size()) {
        rep(i,y.size() - 1) {
            c[i + 1][j] += c[i][j];
        }
    }

    ll ans = 0;
    rep(i,y.size() - 1) {
        rep(j,x.size() - 1) {
            if(c[i][j] > 0) {
                ans += (x[j + 1] - x[j]) * (y[i + 1] - y[i]);
            }
        }
    }

    cout << ans << endl;
    return 0;

}