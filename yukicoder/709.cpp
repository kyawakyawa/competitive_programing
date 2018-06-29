#include<iostream>
#include<vector>
#include<string>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

ll n,m,r[100010][100];
vector<ll> tops[11];
ll cou[100010];
ll maxi[11];


int main() {
    cin >> n >> m;
    rep(i,n){
        rep(j,m) {
            cin >> r[i][j];
        }
    }

    rep(j,m)tops[j].push_back(0);
    cou[0] = m;
    rep(j,m)maxi[j] = r[0][j];
    ll ans = 1;

    cout << ans << endl;
    rep(i,n) {
        if(i == 0)continue;

        bool f = false;
        rep(j,m)if(maxi[j] <= r[i][j]){f = true;cou[i]++;}

        if(f){
            ans++;
            rep(j,m) {
                if(maxi[j] > r[i][j])continue;
                if(maxi[j] < r[i][j]){
                    maxi[j] = r[i][j];
                    for(auto v : tops[j]) {
                        cou[v]--;
                        if(cou[v] == 0)ans--;
                    }
                    tops[j].clear();
                }
                tops[j].push_back(i);
            }
        }
        cout << ans << endl;

    }

    return 0;
}