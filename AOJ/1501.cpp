#include<iostream> 
#include<algorithm>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

ll r,c,a1,a2,b1,b2;
const ll mod = 1e8+7;

ll combi[3000][3000];

void combi_pre_compute(ll n) {
    for(int i = 0;i <= n;i++) combi[0][i] = (i == 0);
    for(int i = 1;i <= n;i++ ) {
        for(int j = 0;j <= i;j++) {
            combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    cin >> r >> c >> a1 >> a2>>b1>>b2;
    combi_pre_compute(r+c);

    ll dr = abs(a1 - b1);
    ll dc = abs(a2 - b2);

    dr = min(dr,r - dr);
    dc = min(dc,c - dc);

    if(dr == r - dr && dc == c - dc) {
        cout << 4 * combi[dr + dc][dr] % mod << endl;
    }else if(dr == r - dr || dc == c - dc) {
        cout << 2 * combi[dr + dc][dr] % mod << endl;
    }else {
        cout << combi[dr + dc][dr] % mod << endl;
    }
}