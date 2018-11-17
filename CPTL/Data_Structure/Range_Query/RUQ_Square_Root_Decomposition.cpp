//Range Update Query
//reference https://kujira16.hateblo.jp/entry/2016/12/15/000000
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename T>
struct RUQ {
  T n;
  T k;//バケットの数
  T sqrt_n;//バケットの大きさ
  vector<T> data;
  vector<T> lazy_update;
  T INF;

  RUQ() = delete;
  RUQ(T n_,T sqrt_n_ = 1000,T INF_ = 1e9) {
    initialize(n_,sqrt_n_,INF_);
  }

  void initialize(T n_,T sqrt_n_ = 1000,T INF_ = 1e9) {
    n = n_;

    sqrt_n = sqrt_n_;

    k = (n + sqrt_n - 1) / sqrt_n;//切り上げ割り算

    data.clear();lazy_update.clear();

    data.resize(k * sqrt_n,INF_);
    lazy_update.resize(k,INF_ + 1);

    INF = INF_;
  }

  void delay_propagation(T bucket_id) {
    if (lazy_update[bucket_id] <= INF) {
      for (int i = bucket_id * sqrt_n;i < (bucket_id + 1) * sqrt_n;i++) {
        data[i] = lazy_update[bucket_id];
      }
      lazy_update[bucket_id] = INF + 1;
    }
  }

  void update(T a,T b,T x) {
    if (a >= sqrt_n * k || b > sqrt_n * k) {
      cerr << "error index k" << endl;
      return;
    }
    if (a >= n || b > n) {
      cerr << "warning index k" << endl;
    }

    rep (i,k) {
      T l = i * sqrt_n,r = (i + 1) * sqrt_n;
      if (b <= l|| r <= a) continue;
      if (l < a || b < r) {
        delay_propagation(i);
        for (int i = max(l,a);i < min(b,r);i++) {
          data[i] = x;
        }
      } else {
        lazy_update[i] = x;
      }
    }
  }

  T get(T i) { // i番目(0-indexed)の値を取得する
    T bucket_id = i / sqrt_n;

    if (lazy_update[bucket_id] > INF)return data[i];
    return lazy_update[bucket_id];
  }
};

using ll = long long;

signed main() {
  ll n,q;
  cin >> n >> q;

  RUQ<ll> ruq(n,1000,(1ll << 31) - 1ll);

  rep(i,q) {
    ll c;
    cin >> c;
    if(c) {
      ll i;
      cin >> i;
      cout << ruq.get(i) << endl;
    } else {
      ll s,t,x;
      cin >> s >> t >> x;
      ruq.update(s,t+1,x);
    }
  }
  return 0;
}
