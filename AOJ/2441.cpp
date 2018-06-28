#include<iostream>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
ll s;

ll calc3(ll x) {
    return x / 3;
}

ll calc5(ll x) {
    return x / 5;
}

ll calc15(ll x) {
    return x / 15;
}

ll calc3(ll a,ll b) {//[a,b)の3の倍数
    return calc3(b-1) - calc3(a-1);
}

ll calc5(ll a,ll b) {//[a,b)の5の倍数
    return calc5(b-1) - calc5(a-1);
}

ll calc15(ll a,ll b) {//[a,b)の15の倍数
    return calc15(b-1) - calc15(a-1);
}

ll calc(const ll x) {
    ll beki = 10;
    ll ret = 0;
    ll i = 1;
    for(i = 1;beki < x;i++,beki*=10) {
        ll I = beki - beki / 10;
        ll a = calc3(beki/10,beki);
        ll b = calc5(beki/10,beki);
        ll c = calc15(beki/10,beki);

        ret += 4 * a + 4 * b + (I - a - b + c) * i;
    }

    ll I = x + 1 - (beki / 10);
    ll a = calc3(beki/10,x+1);
    ll b = calc5(beki/10,x+1);
    ll c = calc15(beki/10,x+1);

    ret += 4 * a + 4 * b + (I - a - b + c) * i;

    return ret;
}

ll C(ll x) {
    return (calc(x) >= s);
}

ll lower_bound(ll s,ll t) {
    ll lb = s - 1,ub = t;

    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        (C(mid) ? ub : lb) = mid;
    }
    return ub;
}


int main() {
    cin >> s;

    ll start = lower_bound(1,1e18 + 1);

    string ans = "";
    for(ll i = start;i < start + 21;i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            if(i % 3 == 0) {
                ans += "Fizz";
            }
            if(i % 5 == 0) {
                ans += "Buzz";
            }
        }else {
            ans += to_string(i);
        }
    }

    ll b;
    if(start % 15 == 0)b = 8;
    else if(start % 3 == 0 || start % 5 == 0){
        b = 4;
    }
    else b = to_string(start).size();
    ll d = b - (calc(start) - s) - 1;
    cout << ans.substr(d,20) << endl;
    return 0;
}