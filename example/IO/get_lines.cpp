// 行単位でstringで入力する
#include <iostream>
#include <vector>
#include <string>

using namespace std;

signed main() {
  vector<string> ss;
  string s;

  while(getline(cin,s)) {
    ss.push_back(s);
  }

  for (auto s : ss) {
    cout << s << endl;
  }
  return 0;
}
