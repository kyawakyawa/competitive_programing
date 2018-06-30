#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

ll dy[] = {1,0,0,-1};
ll dx[] = {0,-1,1,0};


struct edge {
    ll to;
    ll cap;
    ll rev;
};

#define MAX_V 30000
#define rep(i,n) for(int i=0;i<(n);i++)

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(ll from,ll to,ll cap) {
    G[from].push_back((edge){to,cap,(ll)G[to].size()});
    G[to].push_back((edge){from,0,(ll)G[from].size() - 1});
}

ll dfs(ll v,ll t,ll f) {
    if(v == t)return f;
    used[v] = true;
    for(auto &e : G[v]) {
        if(!used[e.to] && e.cap>0) {
            ll d = dfs(e.to,t,min(f,e.cap));
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
ll h,w;
char S[200][200];

ll id(ll i,ll j) {
    return i * w + j;
}
 
int main() {
    cin >> h >> w;
    rep(i,h)cin >> S[i];
    rep(i,h)rep(j,w) {
        rep(k,4) {
            ll y = dy[k] + i;
            ll x = dx[k] + j;

            if(y >= 0 && y < h && x >= 0 && x < w) {
                add_edge(id(i,j) + h * w,id(y,x),1e18);
            }
        }
    }

    ll s = h * w * 2;
    ll t = h * w * 2 + 1;

    rep(i,h)rep(j,w) {
        if(S[i][j] == 'X') {
            add_edge(s,id(i,j),1e18);
            add_edge(id(i,j),id(i,j) + h * w,1e18);
        }else {
            add_edge(id(i,j),id(i,j) + h * w,1);
        }
    }

    rep(i,h)rep(j,w) {
        if(i == 0 || i == h - 1 || j == 0 || j == w - 1) {
            if(S[i][j] == 'X') {
                cout << -1 << endl;
                return 0;
            }
            add_edge(id(i,j) + h * w,t,1e18);
        }
    }

    cout << max_flow(s,t) << endl;
}