#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define INF 1e9
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> iP;
struct edge{P to;int cost;};

map<P,vector<edge> > G;
int p[200001],q[200001],c[200001];
int n,m;
map<P,int> d;

void dijkstra() {
    priority_queue<iP,vector<iP>,greater<iP> > que;

    que.push(iP(0,P(0,-1)));
    d[P(0,-1)] = 0;

    while(!que.empty()) {
        iP p = que.top();que.pop();
        if(d[p.second] < p.first) continue;
        rep(i,G[p.second].size()) {
            if(d.find(G[p.second][i].to)==d.end()||d[G[p.second][i].to] > d[p.second] + G[p.second][i].cost ) {
                d[G[p.second][i].to] = d[p.second] + G[p.second][i].cost;
                que.push(iP(d[G[p.second][i].to],G[p.second][i].to));
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    rep(i,m) {
        cin >> p[i] >> q[i] >> c[i];
        p[i]--;q[i]--;
        G[P(p[i],c[i])] = vector<edge>();
        G[P(q[i],c[i])] = vector<edge>();
    }

    rep(i,m) {
        G[P(p[i],c[i])].push_back((edge){P(q[i],c[i]),0});
        G[P(q[i],c[i])].push_back((edge){P(p[i],c[i]),0});
    }
    rep(i,n)G[P(i,-1)] = vector<edge>();

    rep(i,m) {
        G[P(p[i],c[i])].push_back((edge){P(p[i],-1),0});
        G[P(q[i],c[i])].push_back((edge){P(q[i],-1),0});
        G[P(p[i],-1)].push_back((edge){P(p[i],c[i]),1});
        G[P(q[i],-1)].push_back((edge){P(q[i],c[i]),1});
    }

    dijkstra();

    if(d.find(P(n-1,-1)) != d.end())cout << d[P(n-1,-1)] << endl;
    else cout << -1 << endl;

    return 0;
}
