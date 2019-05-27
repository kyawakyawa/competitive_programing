#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

struct edge {ll to,cost;};

typedef pair<ll,ll> P;

#define MAX_V 100000
#define INF (1e18)

ll V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    priority_queue<P,vector<P>,greater<P> > que;

    fill(d,d+V,INF);

    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;

        if(d[v] < p.first)continue;

        for(auto e : G[v]) {
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

ll E,r;

int main() {
    cin >> V >> E >> r;
    rep(i,E) {
        ll s,t,d;
        cin >> s >> t >> d;
        G[s].push_back((edge){t,d});
    }
    dijkstra(r);

    rep(i,V) 
        if(d[i] < INF)
            cout  << d[i] << endl;
        else 
            cout << "INF" << endl;
    return 0;
}