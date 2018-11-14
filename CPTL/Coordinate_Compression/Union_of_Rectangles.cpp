//Coordinate Compression 2Dver
// refference https://minus9d.hatenablog.com/entry/20120623/1340457351
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
#include<iostream>
#include<vector>

#define USE_SET

#ifdef USE_SET
#include<set>
#endif

#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T>
struct Coordinate_Compression_2D {
  int N;
  vector<T> x,y;
  vector<T> x1,x2,y1,y2;

  Coordinate_Compression_2D() = delete;
  Coordinate_Compression_2D(T *x1_,T *x2_,T *y1_,T *y2_,int N_) {
    init(x1_,x2_,y1_,y2_,N_);
  }
  Coordinate_Compression_2D(const vector<T> &x1_,const vector<T> &x2_,const vector<T> y1_,const vector<T> y2_) {
    if (x1_.size() != x2_.size() || x2_.size() != y1_.size() || y1_.size() != y2_.size()) {
      std::cerr << "warning" << std::endl;
      return;
    }
    init(x1_.data(),x2_.data(),y1_.data(),y2_.data(),x1_.size());
  }

  void init (const T *x1_,const T *x2_,const T *y1_,const T *y2_,const int N_) {//[x1,x2) [y1,y2)
    x.clear();y.clear();
    x1.clear(),x2.clear(),y1.clear(),y2.clear();

    N = N_;

    rep(i,N) {
      x1.push_back(x1_[i]);
      x2.push_back(x2_[i]);
      y1.push_back(y1_[i]);
      y2.push_back(y2_[i]);
    }

    rep (i,N) {
      x.push_back(x1[i]);x.push_back(x2[i]);
      y.push_back(y1[i]);y.push_back(y2[i]);
    }

#ifdef USE_SET
    //https://minus9d.hatenablog.com/entry/20120623/1340457351
    set<T> sx(x.begin(),x.end());
    set<T> sy(y.begin(),y.end());

    x = vector<T>(sx.begin(),sx.end());
    y = vector<T>(sy.begin(),sy.end()); 
#else
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());
#endif

  }

  T imos_area () {

    vector<vector<T>> c(y.size(),vector<T>(x.size(),(T)0));

    rep (i,N) {
      T ix1 = lower_bound(x.begin(),x.end(),x1[i]) - x.begin();
      T ix2 = lower_bound(x.begin(),x.end(),x2[i]) - x.begin();
      T iy1 = lower_bound(y.begin(),y.end(),y1[i]) - y.begin();
      T iy2 = lower_bound(y.begin(),y.end(),y2[i]) - y.begin();

      c[iy1][ix1]++;
      c[iy1][ix2]--;
      c[iy2][ix1]--;
      c[iy2][ix2]++;
    }

    rep (i,y.size()) {
      rep (j,(int)x.size() - 1) {
        c[i][j + 1] += c[i][j];
      }
    }

    rep (i,(int)y.size() - 1) {
      rep (j,x.size()) {
        c[i + 1][j] += c[i][j];
      }
    }

    T ret = 0;

    rep (i,(int)y.size() - 1) {
      rep (j,(int)x.size() - 1) {
        if (c[i][j] > 0)
          ret += (x[j + 1] - x[j]) * (y[i + 1] - y[i]);
      }
    }

    return ret;
  }
};

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> x1(n),x2(n),y1(n),y2(n);

  rep (i,n) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  Coordinate_Compression_2D<ll> cc2(x1,x2,y1,y2);

  cout << cc2.imos_area() << endl;
  return 0;
}


