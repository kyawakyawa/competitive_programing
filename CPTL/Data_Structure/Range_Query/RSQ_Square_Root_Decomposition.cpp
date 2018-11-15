//Range Sum Query
//reference https://kujira16.hateblo.jp/entry/2016/12/15/000000
//verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename T>
struct RSQ {
  T n;
  T k;//`バケットの数
  T sqrt_n;//バケットの大きさ
  vector<T> data;
  vector<T> bucket_sum;

  RSQ() = delete;
  RSQ(T n_,T sqrt_n_ = 1000) {
    initialize(n_,sqrt_n_);
  }

  void initialize(T n_,T sqrt_n_ = 1000) {
    n = n_;

    sqrt_n = sqrt_n_;

    k = (n + sqrt_n - 1) / sqrt_n;//切り上げ割り算

    data.clear();bucket_sum.clear();

    data.resize(k * sqrt_n,0);
    bucket_sum.resize(k,0);
  }

  void update (T i,T a) {// i番目(0-indexed)の値をaに更新
    add(i,a - data[i]);
  }
  void add(T i,T x) {// i番目(0-indexed)の値をxだけ増やす
    if (i >= sqrt_n * k) {
      cerr << "error index k" << endl;
      return;
    }
    if (i >= n) {
      cerr << "warning index k" << endl;
    }

    data[i] += x;
    bucket_sum[i / sqrt_n] += x;
  }
  T query(T a,T b) const {
    T ret = 0;
    rep(i,k) {
      T l = i * sqrt_n,r = (i + 1) * sqrt_n;
      if (b <= l || r <= a)continue;
      if (l < a || b < r) {
        for (int i = max(l,a);i < min(b,r);i++) {
          ret += data[i];
        }
      }else {
        ret += bucket_sum[i];
      }
    }
    return ret;
  }
};

typedef long long ll;
ll n,q;

signed main() {
  cin >> n >> q;

  RSQ<ll> rsq(n);

  rep (i,q) {
    ll c,x,y;
    cin >> c >> x >> y;
    if(c) {
      x--;y--;
      cout << rsq.query(x,y+1) << endl;
    }else {
      x--;
      rsq.add(x,y);
    }
  }
  return 0;
}

