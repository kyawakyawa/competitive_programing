//Range Add Query
//reference https://kujira16.hateblo.jp/entry/2016/12/15/000000
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template <typename T>
struct RAQ {
  T n;
  T k;//バケットの数
  T sqrt_n;//バケットの大きさ
  vector<T> data;
  vector<T> bucket_sum;

  RAQ() = delete;
  RAQ(T n_,T sqrt_n_ = 1000) {
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

  void add(T a,T b,T x) { //[a,b)(0-indexed)にx を加算
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
        for (int i = max(l,a);i < min(b,r);i++) {
          data[i] += x;
        }
      } else {
        bucket_sum[i] += x;
      }
    }
  }

  T get(T i) { // i番目(0-indexed)の値を取得する
    return data[i] + bucket_sum[i / sqrt_n];
  }
};

using ll = long long;

signed main() {
  ll n,q;
  cin >> n >> q;

  RAQ<ll> raq(n);

  rep(i,q) {
    ll c;
    cin >> c;
    if(c) {
      ll i;
      cin >> i;
      i--;
      cout << raq.get(i) << endl;
    } else {
      ll s,t,x;
      cin >> s >> t >> x;
      s--;t--;
      raq.add(s,t+1,x);
    }
  }
  return 0;
}
