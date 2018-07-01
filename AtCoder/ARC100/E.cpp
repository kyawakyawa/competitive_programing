#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i =0;i <(n);i++) 
#define FOR(i,a,b) for(int i=a;i<(b);i++)

ll n,a[1000000];

ll cou[1000];

int main() {
    cin >> n;
    rep(i,(1<<n)) cin >> a[i+1];

    for(int k = 1;k <= 100;k++) {
        for(int i = 0;i <= k;i++) {
            for(int j = i + 1;j <= k;j++) {
                if((i | j) <= k) {
                    cou[k]++;
                    printf("(%p,%p)",i,j);
                }
            }
        }
        cout << endl;
    }
    printf("\n\n\n");
    for(int k = 2;k <= 100;k++) {
        cout << cou[k] - cou[k-1] << endl;
    }

    return 0;
}