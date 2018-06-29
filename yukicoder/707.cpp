#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

ll h,w;
char in[100][100];
bool p[100][100];

int main() {
    cin >> h >> w;
    rep(i,h)cin >> in[i];
    rep(i,h)rep(j,w) p[i][j] = in[i][j] - '0';

    double ans = 1e9;
    rep(x1,h+2)rep(y1,w+2) {
        double sum = 0;
        ll cou = 0;
        if(x1 == 0)cou++;
        if(x1 == h+1)cou++;
        if(y1 == 0)cou++;
        if(y1 == w+1)cou++;
        if(cou != 1)continue;
        for(int x2 = 1;x2 < h+1;x2++) {
            for(int y2 = 1;y2 < w+1;y2++) {
                if(p[x2 -1][y2-1])sum += sqrt(pow(x1-x2,2) + pow(y1-y2,2));
            }
        }
        ans = min(ans,sum);
    }
    printf("%.10f\n",ans);
    return 0;
}
