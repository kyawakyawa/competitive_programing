//素数を法とするライブラリ


#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

template<typename T>
bool is_prime(T n){
  bool f = true;
  if(n == 1) {
    return 0;
  }
  if(n == 2)
    return true;
  if(n % 2 == 0)
    return false;
  for(int i = 3;i <= (int)(sqrt(n) + 0.1);i += 2){
    if(n % i == 0){
      f = false;
      break;
    }
  }
  return f;
}

template<typename T>
T extend_gcd(T a,T b,T &x,T &y) {
  if (b == 0) {
    x = 1;y = 0;
    return a;
  }
  T r = a % b;
  T d = extend_gcd(b,r,y,x);
  y -= (a / b) * x ;

  return d;
}

template<typename T>
T mod_pow(T x, T n, T mod) {
  T res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod; // 最下位ビットが立っているときにx^(2^i)を掛ける
    x = x * x % mod; // xを順次二乗していく
    n >>= 1;
  }
  return res;
}

template<typename T = long long>
struct Zp {
  T n;//数
  T p;// mod p

  Zp() {
    set(0,1000000007);
  }

  Zp(T n_,T p_) {
    set(n_,p_);
  }

  void set(T n_,T p_ = 1000000007) {
    p = p_;
    n = n_ % p;
    if (n < 0) n = p + n;
  }

  T get() const {
    return n;
  }

  Zp operator +() const {
    return Zp(n,p);
  }

  Zp operator -() const {
    return Zp(-n,p);
  }

  Zp operator + (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う";
    return Zp(n+m.n,m.p);
  }

  Zp operator - (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n-m.n,m.p);
  }
  
  Zp operator * (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n*m.n,m.p);
  }
  
  Zp operator / (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    if (m.n == 0) cerr << "warning! 0わり" << endl;
    T x,y;
    extend_gcd(m.n,m.p,x,y);
    return n * Zp(x,m.p);
  }

  Zp operator % (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う";
    if (m.n == 0) cerr << "warning! 0剰余" << endl;
    return Zp(n%m.n,m.p);
  }

	Zp& operator +=(const Zp& m){
    return *this = *this + m;
	}

	Zp& operator -=(const Zp& m){
    return *this = *this - m;
	}

	Zp& operator *=(const Zp& m){
		return *this = *this * m;
	}

	Zp& operator /=(const Zp& m){
		return *this = *this / m;
	}

	Zp& operator %=(const Zp& m){
		return *this = *this % m;
	}

  Zp pow(const T m) const { //m乗を計算
    return Zp(mod_pow(n,m,p),p);
  }

  Zp inverse() const {
    T x,y;
    extend_gcd(n,p,x,y);
    return Zp(x,p);
  }

  Zp operator & (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n&m.n,m.p);
  }

  Zp operator | (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n|m.n,m.p);
  }

  Zp operator ^ (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n^m.n,m.p);
  }

  Zp operator ~() const {
    return Zp(~n,p);
  }

  Zp operator << (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n<<m.n,m.p);
  }

  Zp operator >> (const Zp &m) const {
    if (p != m.p) cerr << "warning! 法が違う" << endl;
    return Zp(n>>m.n,m.p);
  }

	Zp& operator &=(const Zp& m){
    return *this = *this & m;
	}

	Zp& operator |=(const Zp& m){
    return *this = *this | m;
	}

	Zp& operator ^=(const Zp& m){
		return *this = *this ^ m;
	}

	Zp& operator <<=(const Zp& m){
		return *this = *this << m;
	}

	Zp& operator >>=(const Zp& m){
		return *this = *this >> m;
	}

};

template<typename T>
Zp<T> pow(const Zp<T> &n,T m) {
  return n.pow(m);
}

template<typename T>
Zp<T> inverse(const Zp <T> &n) {
  return n.inverse();
}

#ifdef _NORMAL
template<typename T = long long>
struct Combination {
  T n;//max n
  T p;//mod p
  vector<Zp<T>> factorial;//factorial[n] := n! mod p
  vector<Zp<T>> factorial_inverse;//factorial_inverse[n] = (n!)^-1 mod p

  Combination() = delete;
  Combination(T n_,T p_ = 1000000007) {
    init(n_,p_);
  }

  void init(T n_,T p_) {
    n = n_;p = p_;
    factorial.clear();factorial_inverse.clear();
    factorial.resize(n+1);factorial_inverse.resize(n+1);

    factorial[0].set(1,p);factorial[1].set(1,p);

    for (int i = 2;i <= n;i++) {
      factorial[i] = factorial[i - 1] * Zp<T>(i,p);
    }

    factorial_inverse[n] = inverse(factorial[n]);

    for (int i = n;i > 0;i--) {
      factorial_inverse[i - 1] = factorial_inverse[i] * Zp<T>(i,p);
    }
  }

  Zp<T> calc(T n_,T k_) {
    if(n_ < k_ || n_ < 0 || k_ < 0) return Zp<T>(0,p);//不正な値
    return factorial[n_] * factorial_inverse[k_] * factorial_inverse[n_-k_];
  }
};
#ifdef _WITH_INVERSE
template<typename T = long long>
struct Combination {
  T n;//max n
  T p;//mod p
  vector<Zp<T>> factorial;//factorial[n] := n! mod p
  vector<Zp<T>> factorial_inverse;//factorial_inverse[n] = (n!)^-1 mod p
  vector<Zp<T>> inverse;//inverse[n] := 1 / n mod p;

  Combination() = delete;
  Combination(T n_,T p_ = 1000000007) {
    init(n_,p_);
  }

  void init(T n_,T p_) {
    n = n_;p = p_;
    factorial[0] = factorial[1] = Zp<T> (0,p);
    factorial_inverse[0] = factorial_inverse[1] - 1;
  }

  Zp<T> calc(T n_,T k_) {
    if(n_ < k_ || n_ < 0 || k_ < 0) return Zp<T>(0,p);//不正な値
    return factorial[n_] * factorial_inverse[k_] * factorial_inverse[n_-k_];
  }
};
#endif
using ll = long long;

int main() {
  ll N,A,B,K;
  cin >> N >> A >> B >> K;
  ll mod = 998244353;
  Combination<> C(N,mod);
  Zp<> ans(0,mod);

  rep (i,N+1) {
    ll r = K - A * i;
    if (r >= 0 && r % B == 0) {
      ans += C.calc(N,i) * C.calc(N,r / B);
    }
  }

  cout << ans.get() << endl;
}
