#include<iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

#define MAX_E 2000
#define MAX_V 1000
#define INF (1e18)
struct edge{ll from,to,cost;};

edge es[MAX_E];

ll d[MAX_V];
ll V,E;

bool shortest_path(ll s) {
    fill(d,d+V,INF);

    d[s] = 0;

    rep(i,V) {
        bool update = false;
        rep(j,E) {
            edge e = es[j];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if( !update) break;
        if(update && i == V - 1) {
            return false;;
        }
    }
    return true;
}

ll r;
int main() {
    cin >> V >> E >> r;
    rep(i,E) {
        ll s,t,dd;
        cin >> s >> t >> dd;
        es[i] = (edge){s,t,dd};
    }

    if(shortest_path(r)) {
        rep(i,V) {
            if(d[i] < INF)
                cout << d[i] << endl;
            else 
                cout << "INF" << endl;
        }
    }else {
        cout << "NEGATIVE CYCLE" << endl;
    }

    return 0;
}