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


long n,m,x[2000],y[2000],z[2000],p[2000];

int main(){
	cin >> n >> m;

	for(int i = 0;i < n;i++) cin >> x[i] >> y[i] >> z[i];

	ll ans = 0;
	for(int i = -1;i < 2;i+=2){
		for(int j = -1;j < 2 ;j+=2) {
			for(int k = -1;k < 2;k+=2) {
				ll sum = 0;
				REP(l,n)p[l] = x[l] * i + y[l] * j + z[l] * k; 
				sort(p,p+n);

				REP(l,m) {
					sum += p[n-l-1];
				}
				ans = max(ans,sum);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
