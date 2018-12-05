//Union-Find木
//Extended so that the number of elements of the set and the number of sets are counted(集合の要素数や集合の数が数えられるように拡張)
//reference Programming Contest ChaTenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A

#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename T>
struct Union_Find {

  vector<T> par;//親の番号
  vector<T> urank;//集合のランク
  vector<T> usize;//集合の要素数
  T num;//集合の数

  Union_Find() {
    init(100000);
  }

  Union_Find(T n) {
    init(n);
  }

  void init(T n) {//0〜n-1までの要素を初期化 最初はバラバラ
    par.clear();urank.clear();usize.clear();
    par.resize(n);urank.resize(n);usize.resize(n);
    num = n;
    rep(i,n) {
      par[i] = i;
      urank[i] = (T)0;
      usize[i] = (T)1;
    }
  }

  T find(T x) {//xが属する集合の親を見つける
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }

  T get_usize(T x) {//xが属する集合の要素数を返す。
    return usize[find(x)];
  }

  void unite(T x,T y) {//xが属する集合とyが属する集合を併合する。
    x = find(x);
    y = find(y);
    if(x == y) return;

    T s = usize[x] + usize[y];
    num--;
    if(urank[x] < urank[y]) {
      par[x] = y;
      usize[y] = s;
    } else {
      par[y] = x;
      usize[x] = s;
      if(urank[x] == urank[y]) urank[x]++;
    }
  }

  bool same(T x,T y) {//同じ集合に属するかを判定する
    return find(x) == find(y);
  }

  T num_set() {//集合の数(木の数)を返す。
    return num;
  }
};

using ll = long long;

ll n,q;

int main() {
    cin >> n >> q;
    Union_Find<ll> uf(n);

    rep(i,q) {
        ll com,x,y;
        cin >> com >> x >> y;
        if(com) {
            cout << uf.same(x,y) << endl;
        }else {
            uf.unite(x,y);
        }
    }
    return 0;
}
