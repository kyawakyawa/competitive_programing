#include<iostream>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define INF (1e18)

struct RMQ {
    ll n;
    vector<ll> node;

    RMQ(ll *a_,ll n_) {
        vector<ll> a;
        rep(i,n_)a.push_back(a_[i]);
        initialize(a);
    }
    RMQ(vector<ll> a) {
        initialize(a);
    }

    void initialize(vector<ll> a) {
        ll n_ = (ll)a.size();
        n = 1;
        while(n<n_)n *= 2;

        node.resize(2*n,INF);

        rep(i,n_) node[n + i] = a[i];
        for(int i=n-1;i > 0;i--)node[i] = min(node[2*i],node[2*i+1]);
    }

    void update(ll k,ll a) {// k番目(0-indexed)の値をaに更新
        k += n;
        node[k] = a;

        while(k > 1) {
            k /= 2;
            node[k] = min(node[k * 2],node[k * 2 + 1]);
        }
    }

    ll query(ll a,ll b,ll k=1,ll l=0,ll r=0) {//query(a,b) min{ node[i] | i∈[a,b) } を返す
        //k  節点のインデックス
        //その節点が[l,r)に対応づいている
        if(l>=r)r = n;//外から呼ばれる時 l=0,r=nとする必要があるのでこうなる。
        if(r <= a || b <= l)return INF;//範囲外
        if(a <= l && r <= b)return node[k]; //[a,b)に[l,r)が含まれる

        ll vl = query(a,b,2 * k,l,(l + r) / 2);
        ll vr = query(a,b,2 * k + 1,(l + r) / 2,r);
        return min(vl,vr);
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
ll a[100000];

int main() {
    cin >> n >> q;

    rep(i,n) a[i] = (1ll<<31)-1;

    RMQ rmq(a,n);

    rep(i,q) {
        ll c,x,y;
        cin >> c >> x >> y;
        if(c) {
            cout << rmq.query(x,y + 1) << endl;;
        }else {
            rmq.update(x,y);
        }
    }

    return 0;

}