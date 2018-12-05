//Weighted-Union-Find木
//参考 https://qiita.com/drken/items/cce6fc5c579051e64fab
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B

#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename T>
struct Weighted_Union_Find {

  vector<T> par;//親の番号
  vector<T> urank;//集合のランク
  vector<T> usize;//集合の要素数
  vector<T> diff_weight;//親との距離
  T num;//集合の数

  Weighted_Union_Find() {
    init(100000);
  }

  Weighted_Union_Find(T n) {
    init(n);
  }

  void init(T n) {//0〜n-1までの要素を初期化 最初はバラバラ
    par.clear();urank.clear();usize.clear();diff_weight.clear();
    par.resize(n);urank.resize(n);usize.resize(n);diff_weight.resize(n);
    num = n;
    rep(i,n) {
      par[i] = i;
      urank[i] = (T)0;
      usize[i] = (T)1;
      diff_weight[i] = (T)0;
    }
  }

  T find(T x) {//根の添字を返すと同時に経路圧縮をする
    if(par[x] == x) {
      return x;
    } else {
      T r = find(par[x]);
      diff_weight[x] += diff_weight[par[x]];//累積和
      return par[x] = r;
    }
  }

  T get_usize(T x) {//xが属する集合の要素数を返す。
    return usize[find(x)];
  }

  bool unite(T x,T y,T w) {//weight(y) = weight(x) + w (diff(x,y) = w) となるようにxの属する集合とyの属する集合をマージ
    if(urank[x] < urank[y]) {swap(x,y);w*=-1;}//x(のroot)の下にy(のroot)をつけるので反転

    w += weight(x);w -= weight(y);
    //x(のroot)の下にy(のroot)をつけるので、w=diff(xのroot,yのroot)となるように

    x = find(x);//xの親
    y = find(y);//yの親
    if(x == y) { 
      return diff(x,y) == w;//falseの時矛盾が生じている
    }

    //x(のroot)の下にy(のroot)をつける。
    usize[x] = usize[x] + usize[y];
    num--;
    if(urank[x] == urank[y]) urank[x]++;
    par[y] = x;

    diff_weight[y] = w;

    return true;
  }

  bool same(T x,T y) {//同じ集合に属するかを判定する
    return find(x) == find(y);
  }

  T weight(T x) {//親との距離を求める
    find(x);
    return diff_weight[x];
  }

  T diff(T x,T y) {//xからyに行くときのポテンシャルの増加分 same関数で一緒かどうか調べてから使う
    return weight(y) - weight(x);
  }

  T num_set() {//集合の数(木の数)を返す。
    return num;
  }
};

using ll = long long;

ll n,q;

int main() {
    cin >> n >> q;
    Weighted_Union_Find<ll> wuf(n);

    rep(i,q) {
      ll com,x,y,z;
      cin >> com;
      if(com) {
        cin >> x >> y;
          if(wuf.same(x,y))cout << wuf.diff(x,y) << endl;
          else cout << "?" << endl;
      }else {
        cin >> x >> y >> z;;
        wuf.unite(x,y,z);
      }
  }
    return 0;
}
