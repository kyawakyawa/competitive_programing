//ford-fulkerson法 
//O(F|E|)

//参考　蟻本！
//judge http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp

#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++) 
#define MAX_V (1000)

struct edge{
        ll to; /*どの頂点に向かうか*/ 
        ll cap; /*現在の辺のキャパシティ*/ 
        ll rev_id;/*逆辺の添字*/ 
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(ll from,ll to,ll cap) {
    G[from].push_back((edge){to,cap,(ll)G[to].size()});//辺の追加
    G[to].push_back((edge){from,0,(ll)G[from].size() - 1});//辺の逆辺
}

ll dfs(ll v,ll t,ll f) {
    if(v == t)return f;//終点についたらフローを返す。

    used[v] = true;

    rep(i,G[v].size()) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            ll d = dfs(e.to,t,min(f,e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev_id].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(ll s/*始点*/,ll t/*終点*/) {
    ll flow = 0;
    for(;;) {
        fill(used,used+MAX_V,false);
        ll f = dfs(s,t,1000000000);
        if(f == 0)break;
        flow += f;
    }
    return flow;
}

int main() {
    ll V,E;
    cin >> V >> E;

    rep(i,E) {
        ll u,v,c;
        cin >> u >> v >> c;
        add_edge(u,v,c);
    }

    cout << max_flow(0,V-1) << endl;
    return 0;
}