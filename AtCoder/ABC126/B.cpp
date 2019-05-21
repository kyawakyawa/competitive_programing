#include <iostream>
#include <string>

using namespace std;

#define rep(i,n) for(int i =0;i<(n);i++)

string s;

bool check(char a, char b) {
  int n = (a - '0') * 10 + (b - '0');

  return (n > 0) && (n < 13);
}
int main(void) {
  cin >> s;

  if (check(s[0],s[1]) && check(s[2],s[3])) {
    printf("AMBIGUOUS\n");
  } else if ((!check(s[0],s[1])) && (!check(s[2],s[3]))) {
    printf("NA\n");
  } else if (check(s[0],s[1])) {
    printf("MMYY\n");
  } else {
    printf("YYMM\n");
  }

  return 0;
}