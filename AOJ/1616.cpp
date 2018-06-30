#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n,m,a[1000];

map<int,int> c;

int main() {
    while(true) {
        cin >> n >> m;
        if(n == 0)break;
        rep(i,n){
            cin >> a[i];
            c[a[i]] = 0;
        }
        rep(i,n) {
            c[a[i]]++;
        }
        //c[i]はa[j] = i となるｊの個数を格納しておく
        sort(a,a+n);//aをソート

        int ans = -1;
        rep(i,n) {
            auto itr = upper_bound(a,a+n,m - a[i]);//m-a[i]<a[j] となる最小のjのa[j]へのポインタを取得　ここが二分探索
            if(itr - a == 0) {//m - a[i]>=a[j]を満たすjが存在しない時
                continue;
            }
            itr--;//ポインタを一つ減算してm-a[i]>=a[j]となる最大のjのa[j]へのポインタを取得
            if(*itr == a[i] && c[a[i]] < 2) {//境界のものがa[i]だった時
                if(itr - a == 0) {//a[i]未満のものがない時
                    continue;
                }
                itr--;//さらに一つ前に
            }
            ans = max(ans,*itr + a[i]);
        }
        if(ans == -1)cout << "NONE" << endl;
        else cout << ans << endl;
    }

    return 0;
}