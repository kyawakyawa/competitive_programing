#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);i++)
#define MAX_V (1001)

struct edge {
    P to;
    ll cap;
    ll rev_id;
};

map<P,vector<edge> > G;

set<P> used;

void add_edge(P from,P to,ll cap) {
    G[from].push_back((edge){to,cap,(ll)G[to].size()});
    G[to].push_back((edge){from,0,(ll)G[from].size() - 1});
}

ll dfs(P v,P t,ll f) {
    if(v == t)return f;
    used.insert(v);

    rep(i,G[v].size()) {
        edge &e = G[v][i];
        if(used.find(e.to) == used.end() && e.cap > 0) {
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

ll max_flow(P s/*始点*/,P t/*終点*/) {
    ll flow = 0;
    for(;;) {
        used.clear();
        ll f = dfs(s,t,1e18);
        if(f == 0)break;
        flow += f;
    }
    return flow;
}
ll N,M,d,u[1001],v[1001],p[1001],q[1001],w[1001];
int main() {
    cin >> N >> M >> d;
    rep(i,M) cin >> u[i] >> v[i] >> p[i] >> q[i] >> w[i]; 
    rep(i,M) {
        u[i]--;v[i]--;
        G[P(u[i],p[i])] = vector<edge>();
        G[P(v[i],q[i] + d)] = vector<edge>();
    }

    G[P(0,0)] = vector<edge>();
    G[P(N-1,2000000000)] = vector<edge>();

    rep(i,M) {
        add_edge(P(u[i],p[i]),P(v[i],q[i] + d),w[i]);
    }

    for(auto x : G) {
        P q = P(-1,-1);
        for(auto y : G) {
            if(x.first.first == y.first.first && x.first.second < y.first.second) {
                if(q == P(-1,-1) || y.first.second < q.second) {
                    q = y.first;
                }
            }
        }
        if(q != P(-1,-1)) {
            add_edge(x.first,q,1e18);
        }
    }

    cout << max_flow(P(0,0),P(N-1,2000000000)) << endl;

    return 0;
}