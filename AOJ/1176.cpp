#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
int h,w,s,u[200][200];
int c[40][40][40][40];
int mini,sum;
int INF = 1e9;
#define fi first
#define sc second

typedef pair<int,int> P;

int cou(int mh,int mw,int Mh,int Mw) {
    int ret = 0;
    FOR(i,mh,Mh) {
        FOR(j,mw,Mw) {
            ret += u[i][j];
        }
    }
    return ret;
}

bool used[40][40][40][40];
P memo[40][40][40][40];

P solve(int mh,int mw,int Mh,int Mw) {

    if(c[mh][mw][Mh][Mw] < mini) {
        used[mh][mw][Mh][Mw] = true;
        return memo[mh][mw][Mh][Mw] = P(-INF,0);
    }

    if(used[mh][mw][Mh][Mw]) {
        return memo[mh][mw][Mh][Mw];
    }

    P ret(P(1,max(sum - c[mh][mw][Mh][Mw],0)));

    FOR(i,mh,Mh-1) {
        P p = solve(mh,mw,i+1,Mw);
        P q = solve(i+1,mw,Mh,Mw);

        p.fi += q.fi;
        p.sc = max(p.sc,q.sc);

        if(ret.fi != p.fi) ret = (p.fi > ret.fi) ? p : ret;
        else ret = (p.sc < ret.sc) ? p : ret;
    }
    FOR(i,mw,Mw-1) {
        P p = solve(mh,mw,Mh,i+1);
        P q = solve(mh,i+1,Mh,Mw);
        p.fi += q.fi;
        p.sc = max(p.sc,q.sc);

        if(ret.fi != p.fi) ret = (p.fi > ret.fi) ? p : ret;
        else ret = (p.sc < ret.sc) ? p : ret;
    }
    used[mh][mw][Mh][Mw] = true;
    return memo[mh][mw][Mh][Mw] = ret;
}

int main() {
    while(true) {
        cin >> h >> w >> s;
        if(h == 0)
            break;

        rep(i,h)rep(j,w) cin >> u[i][j];
        rep(i,h)rep(j,w)FOR(k,i+1,h+1)FOR(l,j+1,w+1)c[i][j][k][l] = cou(i,j,k,l);

        rep(i,h+1)rep(j,w+1)rep(k,h+1)rep(l,w+1)used[i][j][k][l] = false;

        mini = c[0][0][h][w] - s;
        sum = c[0][0][h][w];
        P ans = solve(0,0,h,w);
        cout << ans.fi << " " << s - ans.sc << endl;
    } 
}