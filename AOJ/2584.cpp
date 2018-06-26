#include<iostream> 
#include<string>
#include<algorithm>
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
		}else if(s[i] == '?')ret.pb('A');
		else if(s[i] == '+' || s[i] == '-') {
			int j = 0;
			while(s[i] == '+' || s[i] == '-') {
				j += d[s[i]];
				i++;
			}
			if(s[i] == '?') {
				ret.pb('A');	
			}else {
				s[i] -= 'A';
				j = (j + 26 * 100) % 26;
				s[i] = (s[i] + j + 26) % 26;
				s[i] += 'A';
				ret.pb(s[i]);
			}
		}else {
			int cou = 1;
			int start = i + 1;
			while(cou > 0) {
				i++;
				if(s[i] == '[') {
					cou++;
				}else if(s[i] == ']') {
					cou--;
				}
			}
			if(i - start > 0) {
				string t = s.substr(start,i - start);
				/*for(auto &c : t) {
					if(c == '[') c = ']';
					else if(c == ']') c = '[';
				}*/
				//cerr << "aaa    " << t << endl;
				t = ps(t);
				reverse(t.begin(),t.end());
				ret += t;
			}
		}
	}
	return ret;
}

int main(){
	while(1) {
		cin >> s;
		if(s == ".")break;

		d['+'] = 1;
		d['-'] = -1;
		cout << ps(s) << endl;
	}
	return 0;
}
