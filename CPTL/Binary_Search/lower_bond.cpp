/*判定関数C(x) T→ bool ( x∈[s,t) ) 
  C(X) は　広義単調増加 つまり 0,0,0,...0,1,1,1,...1
  ただし C(x) ≡ 0 または C(x) ≡ 1 の場合もありうる
  
  この時C(x) = 1を満たす最小のｘを返す ただしtが帰ってきたらすべて 0 ということ
*/
//O(log(t - s))
//参考 https://qiita.com/hamko/items/794a92c456164dcc04ad

#include<iostream>
using namespace std;

template<typename T>
bool C(T x) {
    // 上の条件を満たす関数
    return false;
}

template<typename T>
T lower_bound(T s,T t,  bool (*comp)(T x) = C) {
    T lb = s - 1,ub = t;

    while(ub - lb > 1) {
        T mid = (ub + lb) / 2;//ub lb がともに大きい時オーバフローするので注意
        ((*comp)(mid) ? ub : lb) = mid;
    }
    
    return ub;//ub = t のときはすべてfalse
}

int main() {
  cout << lower_bound(1,100) << endl;//100が変える
  return 0;
}
