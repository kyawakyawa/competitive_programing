//最小費用流問題を解く
//与えられるグラフに費用が負の辺があっても良いが、負の閉路があるとまずい
//計算量O(F|V||E|)
//参考 蟻本
//verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B

#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)

struct edge { 
    ll to;//行き先の頂点
    ll cap;//辺の容量
    ll cost;//１フローあたりのコスト
    ll rev;//逆辺のインデックス(G[e.to][e.rev]で逆辺にアクセスできる。)
};

#define MAX_V 1000
#define INF (1e18)

ll V;//頂点数 ここに頂点数をセットするのを忘れないように。
vector<edge> G[MAX_V];
ll dist[MAX_V];//sから各頂点への最短距離
ll prevv[MAX_V],preve[MAX_V]; // 直前の頂点と辺

void add_edge(ll from,ll to,ll cap,ll cost) {
    G[from].push_back((edge){to,cap,cost,(ll)G[to].size()});//辺の追加
    G[to].push_back((edge){from,0,-cost,(ll)G[from].size() - 1});//辺の逆辺
}

// 最小費用流を求める(sからt)
// 流せない場合はINFをかえす。

ll min_cost_flow (ll s,ll t,ll f) {
    ll ret = 0;

    while(f > 0) {
        //ベルマンフォード
        fill(dist,dist + V,INF);
        dist[s] = 0;
        bool update = true;
        while(update) {//最初に負の閉路があると無限ループになるので注意
            update = false;
            rep(v,V) {
                if(dist[v] == INF) continue;
                rep(i,G[v].size()) {
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {//まだフローを流すことが出来、より距離が小さい
                        dist[e.to] = dist [v] + e.cost;//最小距離を更新
                        prevv[e.to] = v;//前の頂点を記録
                        preve[e.to] = i;//辺の添字を記録 求めたパスである頂点uに入る辺はG[prevv[u]][preve[u]]で表す
                        update = true;
                    }
                }
            }
        }

        if(dist[t] == INF) {
            //正のフローを流せるs-t道がなかった
            return -1;
        }

        // s-t間最短路に沿って目一杯流す
        ll d = f;//残りのフロー
        for(ll v = t;v != s;v = prevv[v]) {//t側から更新していく
            d = min(d,G[prevv[v]][preve[v]].cap);//パスの容量
        }
        f -= d;
        ret += d * dist[t];//総費用の更新
        for(ll v = t;v != s;v = prevv[v]) {//残余ネットワークの更新
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return ret;
}

ll E,F;

int main() {
    cin >> V >> E >> F;
    rep(i,E) {
        ll u,v,c,d;
        cin >> u >> v >> c >> d;
        add_edge(u,v,c,d);
    }
    cout << min_cost_flow(0,V-1,F) << endl;;
    return 0;
    
}