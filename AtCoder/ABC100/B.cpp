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



int main(){
	int d,n;
	cin >> d >> n;

	if(d == 0) {
		if(n<100)cout << n << endl;
		else cout << 101 << endl;
	}
	else if(d == 1){
		if(n<100)
			cout << 100 * n << endl;
		else cout << 10100 << endl;
	}
	else if(d == 2) {
		if(n<100)cout << 10000 * n << endl;
		else cout << 100010000;
	}

	return 0;
}
