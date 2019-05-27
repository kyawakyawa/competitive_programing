// 木の直径を求める
// 任意の点からの最遠の頂点を調べそこから最遠の頂点までの距離が直径
//　今度証明しよう
// 参考 http://artak.hatenablog.com/entry/2014/02/20/114126

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);i++)

struct edge{ll to,cost;};
ll n;
vector<edge> G[100000];
bool used[100000];

P dfs(ll v) {
    used[v] = true;
    P ret = P(0,v);

    for(auto e : G[v]) {
        if(used[e.to])continue;
        P p = dfs(e.to);
        ret = max(ret,P(p.first + e.cost,p.second));
    }

    return ret;
}

int main() {
    cin >> n;
    rep(i,n-1) {
        ll s,t,w;
        cin >> s >> t >> w;
        G[s].push_back((edge){t,w});
        G[t].push_back((edge){s,w});
    }

    P p = dfs(0);
    fill(used,used+n,0);
    cout << dfs(p.second).first << endl;
    return 0;
}