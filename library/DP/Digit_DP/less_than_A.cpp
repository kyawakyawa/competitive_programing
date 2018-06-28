//A以下の非負整数の数を求める
//参考ページ https://pekempey.hatenablog.com/entry/2015/12/09/000603

#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

ll  dp[100][2];//上からi桁目まで決まっていて、jがlessかどうかの真理値

const ll p = 1e9+7;

int main() {
    string A;
    cin >> A;
    ll n = A.length();

    dp[0][0] = 1;//まだ選んでいないのでless=0のみ１にする

    for(ll i = 0;i < n;i++) for(int j = 0;j < 2;j++) {
        ll lim = j ? 9 : A[i] - '0';

        for(ll d = 0;d <= lim;d++) {
            (dp[i + 1][j/*既にless=1*/ || d < lim/*この桁からless=1*/] += dp[i][j]) %= p;
        }
    }

    ll ans = 0;
    for(ll j = 0;j < 2;j++)(ans += dp[n][j]) %= p;
    cout << ans << endl;
    return 0;
}