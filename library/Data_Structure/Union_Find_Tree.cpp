//Union-Find木
//集合の要素数や集合の数が数えられるように拡張
//参考 蟻本
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A

#include<iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

#define MAX_N 500000//頂点の最大数

ll par[MAX_N];//親の番号
ll urank[MAX_N];//集合のランク
ll usize[MAX_N];//集合の要素数
ll num;//集合の数

void init(int n) {//0〜n-1までの要素を初期化 最初はバラバラ
    num = n;
    rep(i,n) {
        par[i] = i;
        urank[i] = 0;
        usize[i] = 1;
    }
}

ll find(ll x) {//xが属する集合の親を見つける
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

ll get_usize(ll x) {//xが属する集合の要素数を返す。
    return usize[find(x)];
}

void unite(ll x,ll y) {//xが属する集合とyが属する集合を併合する。
    x = find(x);
    y = find(y);
    if(x == y) return;

    ll s = usize[x] + usize[y];
    num--;
    if(urank[x] < urank[y]) {
        par[x] = y;
        usize[y] = s;
    } else {
        par[y] = x;
        usize[x] = s;
        if(urank[x] == urank[y]) urank[x]++;
    }
}

bool same(ll x,ll y) {//同じ集合に属するかを判定する
    return find(x) == find(y);
}

ll num_set() {//集合の数(木の数)を返す。
    return num;
}

ll n,q;

int main() {
    cin >> n >> q;
    init(n);

    rep(i,q) {
        ll com,x,y;
        cin >> com >> x >> y;
        if(com) {
            cout << same(x,y) << endl;
        }else {
            unite(x,y);
        }
    }
}