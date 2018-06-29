#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

struct edge {
    ll to;
    ll cap;
    ll rev_id;
};

vector<edge> G[1000];
bool used[1000];

void add_edge(ll from,ll to,ll cap) {
    G[from].push_back((edge){to,cap,(ll)G[to].size()});
    G[to].push_back((edge){from,0,(ll)G[from].size() - 1});
}

ll dfs(ll v,ll t,ll f) {
    if(v == t)return f;
    used[v] = true;

    for(int i = 0;i < G[v].size();i++) {
        auto &e = G[v][i];
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

ll max_flow(ll s,ll t) {
    ll flow = 0;
    for(;;) {
        fill(used,used+1000,false);
        ll f = dfs(s,t,1e18);
        if(f == 0)break;
        flow += f;
    }
    return flow;
}

ll n,g,e,p[200];
int main() {
    cin >> n >> g >> e;
    rep(i,g)cin >> p[i];
    rep(i,e) {
        ll a,b;
        cin >> a >> b;

        add_edge(a,b,1);
        add_edge(b,a,1);
    }

    rep(i,n) {
        if(i == 0)continue;
        add_edge(i,i+n,1);
    }

    rep(i,g) {
        add_edge(p[i] + n,2 * n,1e18);
    }

    cout << max_flow(0,2*n) << endl;
}