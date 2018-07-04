//最小費用流問題を解く
//最短路を求めるのにダイクストラ法を使う
//与えられるグラフに費用が負の辺があると正しく動かない。
//そのような場合は最初だけベルマンフォード法を用いらなければならない。
//計算量O(F|E|log|V|)
//参考 蟻本
//verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);i++)

struct edge { 
    ll to;//行き先の頂点
    ll cap;//辺の容量
    ll cost;//１フローあたりのコスト
    ll rev;//逆辺のインデックス(G[e.to][e.rev]で逆辺にアクセスできる。)
};

#define MAX_V 1000
#define INF (1e9)

ll V;//頂点数 ここに頂点数をセットするのを忘れないように。
vector<edge> G[MAX_V];
ll h[MAX_V]; //ポテンシャル
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
    fill(h,h + V,0); // hを初期化 h_-1(v)=0とする。

    //f_0の残余ネットワークはもとのグラフ

    while(f > 0) {
        //現在f_iの残余ネットワークにおけるs-v最短路h_iを求める。
        //蟻本よりポテンシャルとしてh_i-1を使っても良い
        priority_queue<P,vector<P>,greater<P> > que;
        fill(dist,dist + V,INF);
        dist[s] = 0;
        que.push(P(0,s));
        while(!que.empty()) {
            P p = que.top(); que.pop();
            ll v = p.second;//頂点番号
            if(dist[v] < p.first) continue;//すでに最小値が求まっていた。
            rep(i,G[v].size()) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to],e.to));
                } 
            }
        }

        if(dist[t] == INF) {
            //正のフローを流せるs-t道がなかった
            return -1;
        }
        rep(v,V) h[v] += dist[v];//INFのオーバーフローに注意
        //h_i(v) = (上で求まった最短距離)+h_i-1(v)-h_i-1(s)
        //で今、負の閉路が無いのでh_i-1(s)=0となるのでこのような式となる。

        //続いてf_i+1の残余ネットワークを求めていく。
        //f_i残余ネットワークにおけるs-t間最短路に沿って目一杯流す(上で求めたh_iよりわかる)
        ll d = f;//新たに流すフローの量を求める。
        for(ll v = t;v != s;v = prevv[v]) {//t側から更新していく
            d = min(d,G[prevv[v]][preve[v]].cap);//パスの容量を求めている
        }
        f -= d;
        ret += d * h[t];//総費用の更新
        //h_i(t)はf_i残余ネットワークにおけるs-t間最短距離
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