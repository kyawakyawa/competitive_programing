/*判定関数C(x) T→bool ( x∈[s,t) ) 
  C(X) は　広義単調増加 つまり 0,0,0,...0,1,1,1,...1
  ただし C(x) ≡ 0 または C(x) ≡ 1 の場合もありうる
  
  この時C(x) = 1を満たす最小のｘを返す ただしtが帰ってきたらすべて 0 ということ
*/
//参考 https://qiita.com/hamko/items/794a92c456164dcc04ad

bool C(long long x) {
    // 上の条件を満たす関数
    return false;
}

long long lower_bound(long long s,long long t) {
    long long lb = s - 1,ub = t;

    while(ub - lb > 1) {
        long long mid = (ub + lb) / 2;
        (C(mid) ? ub : lb) = mid;
    }
    
    return ub;//ub = t のときはすべてfalse
}