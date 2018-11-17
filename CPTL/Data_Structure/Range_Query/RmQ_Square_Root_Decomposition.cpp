//Range Minimum Query
//reference https://kujira16.hateblo.jp/entry/2016/12/15/000000
//verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename T>
struct RmQ {
  T n;
  T k;//バケットの数
  T sqrt_n;//バケットの大きさ
  vector<T> data;
  vector<T> bucket_min;
  T INF;

  RmQ() = delete;
  RmQ(T n_,T sqrt_n_ = 1000,T INF_ = 1e9) {
    initialize(n_,sqrt_n_,INF_);
  }

  void initialize(T n_,T sqrt_n_ = 1000,T INF_ = 1e9) {
    n = n_;

    sqrt_n = sqrt_n_;

    k = (n + sqrt_n - 1) / sqrt_n;

    data.clear();bucket_min.clear();

    data.resize(k * sqrt_n,INF_);
    bucket_min.resize(k,INF_);

    INF = INF_;
  }

  void update(T i,T x) {// i番目(0-indexed)の値をxにする
    if ( i >= sqrt_n * k) {
      cerr << "error index k" << endl;
      return;
    }
    if (i >= n) {
      cerr << "warning index k" << endl;
    }

    data[i] = x;

    int j = i / sqrt_n;

    bucket_min[j] = INF;
    for (int l = j * sqrt_n;l < (j + 1) * sqrt_n;l++)
      bucket_min[j] = min(data[l],bucket_min[j]);

  }

  T query(const T a,const T b) const { // [a,b)の最小値
    T ret = INF;
    rep (i,k) {
      const T l = i * sqrt_n,r = (i + 1) * sqrt_n;
      if (b <= l || r <= a) continue;
#if 0
      if (a <= l && r <= b) {
        ret = min(ret,bucket_min[i]);
      } else {
        for (int i = max(l,a);i < min(r,b);i++) {
          ret = min(ret,data[i]);
        }
      }
#else 
      if(l < a || b < r) {
        for (int i = max(l,a);i < min(r,b);i++) {
          ret = min(ret,data[i]);
        }
      } else {
        ret = min(ret,bucket_min[i]);
      }
#endif
    }
    return ret;
  }

  bool check()const {
    bool ret = false;
    rep (i,k) {
      T min_a = INF;

      for (int j = sqrt_n * i;j < (i + 1) * sqrt_n;j++) {
        min_a = min(min_a,data[j]);
      }

      T min_b = bucket_min[i];

      if (min_a != min_b) {
        cerr << "error! " << i << "th bucket_min  data:" << min_a << " bucket_min:" << min_b << endl;
        ret = true;
      }
    }
    return ret;
  }
};

typedef long long ll;
ll n,q;

signed main() {
  cin >> n >> q;

  RmQ<ll> rmq(n,1000,(1ll << 31) - 1ll);

  rep (i,q) {
    ll c,x,y;
    cin >> c >> x >> y;

    if (c) {
      cout << rmq.query(x,y+1) << endl;
    } else {
      rmq.update(x,y);
    }
  }
  return 0;
}
