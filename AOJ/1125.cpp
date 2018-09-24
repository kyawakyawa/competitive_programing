#include<iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int x[1000],y[1000];
int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0)break;
        int w,h;
        cin >> w >> h;

        rep(i,n)cin >> x[i] >> y[i];
        int s,t;
        cin >> s >> t;

        int ans = 0;
        for(int i = 1;i <= w - s + 1;i++) {
            for(int j = 1;j <= h - t + 1;j++) {
                int sum = 0;
                rep(k,n) {
                    if(i <= x[k] && x[k] < i + s && j <= y[k] && y[k] < j + t) {
                        sum++;
                    }
                }
                ans = max(sum,ans);
            }
        }
        cout << ans << endl;
    }
    return 0;

}