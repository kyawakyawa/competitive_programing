#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

struct edge {
    ll to;
    ll cap;
    ll rev;
};

#define MAX_V 5000

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(ll from,ll to,ll cap) {
    G[from].push_back((edge){to,cap,(ll)G[to].size()});
    G[to].push_back((edge){from,0,(ll)G[from].size() - 1});
}

ll dfs(ll v,ll t,ll f) {
    if(v == t) return f;
    used[v] = true;
    rep(i,G[v].size()) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            ll d = dfs(e.to,t,min(e.cap,f));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(ll s,ll t) {
    ll flow = 0;
    for(;;) {
        fill(used,used+MAX_V,false);
        ll f = dfs(s,t,1e18);
        if(f == 0)break;
        flow += f;
    }
    return flow;
}
vector<ll> t[MAX_V];//頂点の飛行機が発着する時間
ll N,M,d,u[1001],v[1001],p[1001],q[1001],w[1001];
ll x[2000];

int main() {
    cin >> N >> M >> d;
    rep(i,M)cin >> u[i] >> v[i] >> p[i] >> q[i] >> w[i];

    rep(i,M){
        u[i]--;v[i]--;q[i]+=d;
        t[u[i]].push_back(p[i]);
        t[v[i]].push_back(q[i]);
    }
    t[0].push_back(0);
    t[N-1].push_back(2000000000);

    x[0] = 0;
    rep(i,N) {
        sort(t[i].begin(),t[i].end());
        t[i].erase(unique(t[i].begin(),t[i].end()),t[i].end());
        rep(j,(ll)t[i].size() - 1) {
            add_edge(x[i] + j,x[i] + j + 1,1e18);
        }
        x[i + 1] = x[i] + t[i].size();
    }

    rep(i,M) {
        ll pp;
        rep(j,t[u[i]].size()) {
            if(t[u[i]][j] == p[i]) {
                pp = j;
            }
        }
        ll qq;
        rep(j,t[v[i]].size()) {
            if(t[v[i]][j] == q[i]) {
                qq = j;
            }
        }

        add_edge(x[u[i]] + pp ,x[v[i]] + qq,w[i]);
    }

    cout << max_flow(0,x[N] - 1) << endl;
}