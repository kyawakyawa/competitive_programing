#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n,a[101],b[101],dp[1000000];
int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    dp[0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 100000;j >= a[i - 1];j--) {
            dp[j] = max(dp[j],dp[j - a[i - 1]] + b[i - 1]);
        }
    }

    ll sum = 0;
    for(int i = 0;i < n;i++)sum += b[i];

    ll ans = 1e18;

    for(int i = 0;i <= 100000;i++) {
        ans = min(ans,max((ll)i,sum - dp[i]));
    }
    cout << ans << endl;
}