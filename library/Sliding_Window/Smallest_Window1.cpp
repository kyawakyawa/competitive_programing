#include<iostream>

using namespace std;

typedef long long ll;

#define  rep(i,n) for(int i=0;i<(n);i++)

ll N,S,a[100000];

int main() {
    cin >> N >> S;
    rep(i,N)cin >> a[i];

    ll ans = N + 1;

    ll l = 0,r = 0,sum = 0;//[l,s)

    for(;;) {
        while(r < N && sum < S) {
            sum += a[r++];//条件を満たすまで区間を広げる
        }

        if(sum < S)break;//ｒが後ろまで到達してかつ条件を満たしていない

        ans = min(ans,r - l);
        sum -= a[l++];//lを一つ進める
    }

    if(ans > N) {
        ans = 0;
    }

    cout << ans << endl;
}