#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

struct edge {
    ll to;
    ll cap;
    ll rev;
};

#define MAX_V 50000

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(ll from,ll to,ll cap) {
    G[from].push_back((edge){to,cap,(ll)G[to].size()});
    G[to].push_back((edge){from,0,(ll)G[from].size() - 1});
}

ll dfs(ll v,ll t,ll f) {
    if(v == t) return f;
    used[v] = true;
    for(auto &e : G[v]) {
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
        if(f == 0) break;
        flow += f;
    }
    return flow;
}
ll h,w;
char a[200][200];

ll id(ll i,ll j) {
    return i * w + j;
}

int main() {
    cin >> h >> w;
    rep(i,h)cin >> a[i];

    rep(i,h)rep(j,w) {
        if(a[i][j] == '.')continue;

        for(ll k = i + 1;k < h;k++) {
            if(i == k)continue;
            if(a[k][j] == '.')continue;

            add_edge(id(k,j),id(i,j),1e18);
            add_edge(id(i,j),id(k,j),1e18);
            break;
        }
        for(ll k = j + 1;k < w;k++) {
            if(j == k)continue;
            if(a[i][k] == '.')continue;

            add_edge(id(i,k) + h * w,id(i,j) + h * w,1e18);
            add_edge(id(i,j) + h * w,id(i,k) + h * w,1e18);
            break;
        }
    }

    rep(i,h)rep(j,w) {
        if(a[i][j] == '.')continue;
        if(a[i][j] == 'S' || a[i][j] == 'T') {
            add_edge(id(i,j),id(i,j) + h * w,1e18);
            add_edge(id(i,j) + h * w,id(i,j),1e18);
            continue;
        }
        add_edge(id(i,j),id(i,j) + h * w,1);
        add_edge(id(i,j) + h * w,id(i,j),1);
    }

    ll s,t,si,sj,ti,tj;
    rep(i,h) rep(j,w) {
        if(a[i][j] == 'S') {
            s = id(i,j);
            si = i;
            sj = j;
        }
        if(a[i][j] == 'T') {
            t = id(i,j);
            ti = i;
            tj = j;
        }
    }

    if(si == ti || sj == tj){
        cout << -1 << endl;
    }else{
        cout << max_flow(s,t) << endl;
    }
    return 0;
}