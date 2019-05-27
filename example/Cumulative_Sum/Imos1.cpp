//1次元いもす法の基本的な問題
#include<iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

ll N,T;

ll c[100010];

int main() {
    cin >> N >> T;

    rep(i,N) {
        ll l,r;//時間lに入店、時間rに出店
        cin >> l >> r;//[l,r)
        c[l]++;
        c[r]--;
    }

    rep(i,T) {
        c[i+1] += c[i];
    }

    ll ans = 0;
    rep(i,T+1) {
        ans = max(ans,c[i]);
    }

    cout << ans << endl;
    return 0;
}
