#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int dy[] = {1,0,0,-1};
int dx[] = {0,1,-1,0};
typedef pair<int,int> P;

int w,h;
char c[100][100];
bool used[100][100];
int g[100][100];

int INF = 1000000000;
int d[100][100];
int bfs(P s,P e) {
    rep(i,h)rep(j,w)d[i][j] = INF;

    queue<P> que;

    que.push(s);
    d[s.first][s.second] = 0;

    while(!que.empty()) {
        P p = que.front();
        que.pop();

        rep(i,4) {
            int y = p.first + dy[i],x = p.second + dx[i];
            if(0 <= y && y < h && 0 <= x && x < w && d[y][x] == INF && c[y][x] != 'x') {
                d[y][x] = d[p.first][p.second] + 1;
                que.push(P(y,x));
            }
        }
    }
    return d[e.first][e.second];
}

int main() {
    while(true) {
        cin >> w >> h;
        if(w==0)break;

        rep(i,h)cin >> c[i];

        vector<P> dt;
        rep(i,h)rep(j,w)if(c[i][j] == '*')dt.push_back(P(i,j));
        if(dt.size() == 0){
            cout << 0 << endl;
            continue;
        }

        int perm[dt.size()];

        rep(i,dt.size()) perm[i] = i;

        P s;
        rep(i,h)rep(j,w) if(c[i][j] == 'o')s = P(i,j);

        rep(i,dt.size()) {
            g[dt.size()][i] = g[i][dt.size()] = bfs(s,dt[i]);
        }
        rep(i,dt.size()) {
            for(int j = i + 1;j < dt.size();j++) {
                g[i][j] = g[j][i] = bfs(dt[i],dt[j]);
            }
        }
        /*rep(i,dt.size()+1) {
            rep(j,dt.size()+1) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }*/

        int ans = INF;
        do {
            int sum = g[dt.size()][perm[0]];
            if(sum >= INF)break;

            rep(i,dt.size()-1) {
                sum += g[perm[i]][perm[i+1]];
                if(sum >= INF)break;
            }
            if(sum >= INF)break;
            ans = min(ans,sum);
        }while(next_permutation(perm,perm+dt.size()));
        if(ans < INF)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}