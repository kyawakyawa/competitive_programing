//重み付きUnion-Find木
//参考 https://qiita.com/drken/items/cce6fc5c579051e64fab
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B

#include<iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

#define MAX_N 500000//頂点の最大数

ll par[MAX_N];//親の番号
ll urank[MAX_N];//集合のランク
ll usize[MAX_N];//集合の要素数
ll diff_weight[MAX_N];//親との距離
ll num;//集合の数

void init(ll n) {//初期化
    num = n;
    rep(i,n) {
        par[i] = i;
        urank[i] = 0;
        usize[i] = 1;
        diff_weight[i] = 0;
    }
}

ll find(ll x) {//根の添字を返すと同時に経路圧縮をする
    if(par[x] == x) {
        return x;
    }else {
        ll r = find(par[x]);
        diff_weight[x] += diff_weight[par[x]];//累積和
        return par[x] = r;
    }
}

bool same(ll x,ll y) {
    return find(x) == find(y);
}

ll weight(ll x) {//親との距離を求める
    find(x);
    return diff_weight[x];
}

ll diff(ll x,ll y) {//xからyに行くときのポテンシャルの増加分
    return weight(y) - weight(x);
}

ll get_usize(ll x) {//xが属する集合の要素数を返す。
    return usize[find(x)];
}

bool unite(ll x,ll y,ll w) {//weight(y) = weight(x) + w (diff(x,y) = w) となるようにxの属する集合とyの属する集合をマージ
    if(urank[x] < urank[y]) {swap(x,y);w*=-1;}//x(のroot)の下にy(のroot)をつけるので反転

    w += weight(x);w -= weight(y);
    //x(のroot)の下にy(のroot)をつけるので、w=diff(xのroot,yのroot)となるように

    x = find(x);y = find(y);

    if(x == y) {
        return diff(x,y) == w;
    }

    //x(のroot)の下にy(のroot)をつける。
    if(urank[x] == urank[y]) urank[x]++;
    par[y] = x;

    diff_weight[y] = w;

    return true;
}

ll num_set() {
    return num;
}

ll n,q;
int main() {
    cin >> n >> q;
    init(n);

    rep(i,q) {
        ll c,x,y,z;

        cin >> c;
        if(c) {
            cin >> x >> y;
            if(same(x,y)) cout << diff(x,y) << endl;
            else cout << '?' << endl;
        }else {
            cin >> x >> y >> z;
            unite(x,y,z);
        }
    }
    return 0;
}