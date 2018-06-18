#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<complex>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second

int d[500];

string s;

string ps(string s) {
	string ret = "";
	for(int i = 0;i < s.size();i++) {
		if(s[i] >= 'A' && s[i] <= 'Z'){
			ret.pb(s[i]);
		}else if(s[i] == '?')ret.pb(s[i]);
		else if()
	}
}

int main(){
	while(1) {
		cin >> s;
		if(s == ".")break;

		d['+'] = 1;
		d['-'] = -1;
	}
	return 0;
}
