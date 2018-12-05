//Sliding Minimum Element問題をDequeで解く(O(N))
//長さNの数列が与えられ、すべての長さLの連続した部分列の最小値を求める
//reference Programming Contest ChaTenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D

#include<iostream>
#include<vector>
#include<deque>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<typename T>
vector<T> Sliding_Minimum_Element (const T *a,const T n,const T L) {
  vector<T> ret(n - L + 1);
  deque<T> deq;//デックに入っている値を先頭から順にxiとしたとき、xi<xi+1かつa_{xi} < a_{xi+1} が成り立つ
  //iまで見ていた時、x0∈ [i - L + 1,i] かつ a_{x0}は[i - L + 1,i]で最小 かつ [i - L + 1,i]で最小のものの中で一番大きい添字がx0

  rep(i,n) {
    while(!deq.empty() && a[deq.back()] >= a[i]) deq.pop_back();
    deq.push_back(i);//上の条件を満たすようにしながらdeqにiを入れる

    if (i - L + 1 >= 0) {
      ret[i - L + 1] = a[deq[0]];

      if (deq[0] == i - L + 1){
        deq.pop_front();
      }
    }
  }

  return ret;
}

template<typename T>
vector<T> Sliding_Minimum_Element(const vector<T> a,const T L) {
  return Sliding_Minimum_Element(a.data(),(T)a.size(),L);
}

using ll = long long;

int main() {
  ll N,L;
  cin >> N >> L;

  vector<ll> a(N);
  rep(i,N)cin >> a[i];

  vector<ll> ans = Sliding_Minimum_Element(a,L);

  rep(i,ans.size()) {
    cout << ans[i] << ((i + 1 == ans.size()) ? "" : " ");
  }
  cout << endl;
}
