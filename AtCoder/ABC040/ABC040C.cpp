#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long n,a[1000000];
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    cin >> n;
    rep(i,n)cin >> a[i];

    long d0 = 0,d1 = abs(a[1]-a[0]);

    for(int i = 2;i < n;i++) {
        long d2 = min(abs(a[i]-a[i-2])+d0,abs(a[i]-a[i-1])+d1);
        d0 = d1;
        d1 = d2;
    }
    cout << d1 << endl;
    return 0;
}