#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;

  for (int i = s.size()-1; i >= 0; i--) {
    if (s[i] == '@' && d > 0) {
      s[i] = '.';
      d--;
    }
  }

  cout << s << endl;
}