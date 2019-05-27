#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

struct RSQ {
    ll n;
    vector<ll> node;

    RSQ(ll *a_,ll n_) {
        vector<ll> a;
        rep(i,n_)a.push_back(a_[i]);
        initialize(a);
    }
    RSQ(vector<ll> a) {
        initialize(a);
    }

    void initialize(vector<ll> a) {
        ll n_ = a.size();
        n = 1;
        while(n < n_)n *= 2;

        node.resize(2*n,0);

        rep(i,n_) node[n + i] = a[i];
        for(int i=n-1;i > 0;i--)node[i] = node[2 * i] + node[2 * i + 1];
    }

    void update(ll k,ll a) {// k番目(0-indexed)の値をaに更新
        add(k,a - node[k]);
    }

    void add(ll k,ll x) {// k番目(0-indexed)の値をxだけ増やす
        k += n;

        while(k > 0) {
            node[k] += x;
            k /= 2;
        }
    }

    ll query(ll a,ll b,ll k=1,ll l=0,ll r=0) {//query(a,b) ∑i∈[a,b)node[i] を返す
        //k 節点のインデックス
        //その節点が[l,r)に対応づいている。
        if(l>=r)r = n;//外から呼ばれる時 l=0,r=nとする必要があるのでこうなる。
        if(r <= a || b <= l)return 0;//範囲外
        if(a <= l && r <= b)return node[k];//[a,b)に[l,r)が含まれる

        ll vl = query(a,b,2*k,l,(l + r) / 2);
        ll vr = query(a,b,2*k + 1,(l + r) / 2,r);
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

ll n,q;

int main() {
    cin >> n >> q;
    
    vector<ll> a;
    rep(i,n)a.push_back(0);

    RSQ rsq(a);

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