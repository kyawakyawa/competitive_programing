#include <iostream>
#include <string>

using namespace std;

#define rep(i,n) for(int i =0;i<(n);i++)

long N,K;
string s;
int main(void) {
  cin >> N >> K;
  cin >> s;
  s[K-1] += ('a' - 'A');

  cout << s << endl;
  return 0;
}