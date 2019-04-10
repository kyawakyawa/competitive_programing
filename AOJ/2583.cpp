#include <iostream>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
string ss[1001];

void solve() {
  rep (i,n) {
    string s = ss[i];

    int j = 0;
    while(s[j] == '.')j++; 

    for (int k = 0;k < j - 1;k++) {
      ss[i][k] = ' ';
    }

    if (j - 1 >= 0) ss[i][j - 1] = '+';

    int m = i - 1;
    for (;m >= 0 && ss[m][j - 1] == ' ';m--) {
      ss[m][j - 1] = '|';
    } 
  }

  rep (i,n) {
    cout << ss[i] << endl;
  }
}

int main() {
  while(1) {
    cin >> n;
    if (n > 0) {
      rep(i,n) {
        cin >> ss[i];
      }
      solve();
    } else break;
  }
  return 0;
}
