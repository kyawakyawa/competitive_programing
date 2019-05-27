#include<iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

ll N,K,a[100000],cou[100000];

int main() {
    cin >> N >> K;

    rep(i,N)cin >> a[i];
    rep(i,N)a[i]--;

    ll ans = N + 1;

    ll l = 0,r = 0,used = 0;

    for(;;) {
        while(r < N && used < K) {
            if(a[r] < K && cou[a[r]] == 0)used++;
            cou[a[r]]++;
            r++;
        }

        if(used < K)break;//rが後ろまで到達して勝つ条件を満たしていない

        ans = min(ans,r - l);

        if(a[l] < K && --cou[a[l]] == 0) {
            used--;
        }
        l++;
    }

    if(ans == N + 1) {
        cout << 0 << endl;
    }else {
        cout << ans << endl;
    }
    return 0;
}