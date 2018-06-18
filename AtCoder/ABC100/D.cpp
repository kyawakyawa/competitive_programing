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

long p[200],n,m,x[2000],y[2000],z[2000];

int main(){
	cin >> n >> m;
	REP(i,n) cin >> x[i] >> y[i] >> z[i];

	REP(i,n) p[i] = x[i] + y[i] + z[i];

	sort(p,p+n);

	long ans1 = 0;
	for(int i = 0;i < m;i++) {
		ans1 += p[n-i-1];
	}
	long ans2 = 0;
	for(int i = 0;i < m;i++)
		ans2 += p[i];

	cout << ans << endl;
	return 0;
}
