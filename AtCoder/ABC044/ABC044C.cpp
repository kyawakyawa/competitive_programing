#include<iostream>
using namespace std;

long n,a,x[100];

long dp[3000][100];

int main(int argc, char const *argv[])
{
    cin >> n >> a;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    dp[0][0] = 1;

    for(int i = 0;i < n;i++) {
        for(int j = a*n;j >= x[i];j--) {
            for(int k = n;k > 0;k--) {
                dp[j][k] += dp[j-x[i]][k-1];
            }
        }
    }    
    long ans = 0;
    for(int j = 0;j <= a*n;j++) {
        for(int k = 1;k <= n;k++) {
            if(j % k == 0 && j / k == a)ans += dp[j][k];
        }
    }
    cout << ans << endl;
    return 0;
}
