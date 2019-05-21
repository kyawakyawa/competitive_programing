#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i =0;i<(n);i++)

using P = pair<long,long>; 
vector<P> G[100010];
bool used[100010];
int color[100010];
long N;

void dfs(long i,long d) {
  if ((d % 2 == 0)) color[i] = 0;
  else            color[i] = 1;
  used[i] = true;

  rep(j,G[i].size()) {
    P v = G[i][j];
    if (!used[v.first]) {
      dfs(v.first,v.second + d);
    }
  }
}
int main(void) {

  cin >> N;

  rep(i,N-1) {
    long u,v,w;
    cin >> u >> v >> w;
    u--;v--;
    G[u].push_back(P(v,w));
    G[v].push_back(P(u,w));
  }

  dfs(0,0);

  rep(i,N) {
    cout << color[i] <<  endl;
  }
  return 0;
}