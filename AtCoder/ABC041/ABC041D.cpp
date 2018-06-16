#include<iostream>
#define rep(i,n) for(int i =0;i<(n);i++)

using namespace std;

int n,m;
int x[16*16],y[16*16];
long dp[1<<20];
int g[20][20];

int main() {
    cin >> n >> m;
    rep(i,m){
        cin >> x[i] >> y[i];
        g[x[i]-1][y[i]-1] = 1;
    }

    dp[0] = 1;

    for(int S = 1;S < (1<<n);S++) {
        rep(i,n) {
            if(S & (1<<i)) {
                bool f = true;
                rep(j,n) {
                    if(i != j && (S & (1<<j)) && g[i][j])f=false;
                }
                if(f) {
                    dp[S] += dp[S-(1<<i)];
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;;

    return 0;
}
