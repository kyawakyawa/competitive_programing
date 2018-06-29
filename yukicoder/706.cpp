#include<iostream>
#include<string>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

ll n;
string s[1010];

ll cou[1010];

int main() {
    cin >> n;
    rep(i,n)cin >> s[i];

    rep(i,n) {
        ll sum = 0;
        for(auto c : s[i]) {
            if(c == '^')sum++;
        }
        cou[sum]++;
    }

    ll ans = 0;
    rep(i,1001) {
        if(cou[ans] <= cou[i])ans = i;
    }
    cout << ans << endl;
}