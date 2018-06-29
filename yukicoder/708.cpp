#include<iostream>
#include<string>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

string s;

bool isN(char c) {
    return c >= '0' && c <= '9';
}

ll calc(string s) {
    ll ret = 0;
    bool f = true;
    rep(i,s.size()) {
        if(isN(s[i])) {
            if(f)ret+=s[i]-'0';
            else ret-=s[i]-'0';
        }else if(s[i] == '+')f = true;
        else if(s[i] == '-')f = false;
        else {
            ll j = i;
            while(s[i]!=')')i++;
            ll d =calc(s.substr(j+1,i-j-1));
            if(f)ret+=d;
            else ret-=d;
        }
    }
    return ret;
}

int main() {
    cin >> s;
    cout << calc(s) << endl;
}