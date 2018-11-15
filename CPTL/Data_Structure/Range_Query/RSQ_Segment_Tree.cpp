//Range Sum Query
//reference https://www.slideshare.net/hcpc_hokudai/rmq-47663507
//verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename  T>
struct RSQ {
  T n;
  vector<T> node;

  RSQ(T *a_,T n_) {
      vector<T> a(a_,a_+n_);
      initialize(a);
  }
  RSQ(vector<T> a) {
      initialize(a);
  }

  void initialize(vector<T> a) {
      T n_ = a.size();
      n = 1;
      while(n < n_)n *= 2;

      node.clear();
      node.resize(2*n,0);

      rep(i,n_) node[n + i] = a[i];
      for(int i=n-1;i > 0;i--)node[i] = node[2 * i] + node[2 * i + 1];
  }

  void update(T k,T a) {// k番目(0-indexed)の値をaに更新
      add(k,a - node[k + n]);
  }

  void add(T k,T x) {// k番目(0-indexed)の値をxだけ増やす
      k += n;

      while(k > 0) {
          node[k] += x;
          k /= 2;
      }
  }

  T query(T a,T b,T k=1,T l=0,T r=0) {//query(a,b) ∑_{i ∈ [a,b)} node[i] を返す
      if(a >= b) {
          cerr << "warning wrong range" << endl;
          return 0;
      }
      //k 節点のインデックス
      //その節点が[l,r)に対応づいている。
      if(l>=r)r = n;//外から呼ばれる時 l=0,r=nとする必要があるのでこうなる。
      if(r <= a || b <= l)return 0;//範囲外
      if(a <= l && r <= b)return node[k];//[a,b)に[l,r)が含まれる

      T vl = query(a,b,2*k,l,(l + r) / 2);
      T vr = query(a,b,2*k + 1,(l + r) / 2,r);
      return vl + vr;
  }
  void print() {
      for(int i = 1;i < 2 * n;i++) {
          if(__builtin_popcount(i) == 1)
              cerr << endl;
          cerr << node[i] << " ";
      }
      cerr << endl;
  }
};

typedef long long ll;
ll n,q;

int main() {
    cin >> n >> q;

    vector<ll> a;
    rep(i,n)a.push_back(0);

    RSQ<ll> rsq(a);

    rep(i,q) {
        ll c,x,y;
        cin >> c >> x >> y;

        if(c) {
            x--,y--;
            cout << rsq.query(x,y+1) << endl;
        }else {
            x--;
            rsq.add(x,y);
        }
    }
    return 0;
}