#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;

#define rep(i,n) for(int i=0;i<(n);i++)

const ll MAX_V = 100010;

using P = pair<ll,ll>;

vector<P> G[MAX_V];
bool used[MAX_V];

ll V;

ll prim() {
  priority_queue<P,vector<P>,greater<P> > que;
  rep(i,V)used[i] = false;

  for(auto v : G[0]) {
    que.push(v);
  }

  used[0] = true;

  ll cou = 0;
  ll ret = 0;

  while(cou < V - 1 || !que.empty()) {
    P v = que.top();
    que.pop();

    if(!used[v.second]) {
      ret += v.first;
      used[v.second] = true;
      cou++;
      for(auto w : G[v.second]) {
        if(!used[w.second]) {
          que.push(w);
        }
      }
    }
  }
  return ret;
}

int main() {
  cin >> V;
  ll E;
  cin >> E;

  rep(i,E) {
    ll s,t,w;
    cin >> s >> t >> w;

    G[s].push_back(P(w,t));
    G[t].push_back(P(w,s));
  }

  cout << prim() << endl;
}
