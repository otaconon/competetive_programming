#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int best = 1;
  int ones = 0, twos = 0, slash = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (twos != 0 || slash != 0) {
        ones = 0; twos = 0; slash = 0;
      }
      ones++;
    }
    else if (s[i] == '/') {
      slash++;
      if (twos != 0) {
        ones = 0; twos = 0; slash = 0;
      }
    }
    else {
      twos++;
      if (twos <= ones && slash == 1) {
        best = max(best, twos*2 + 1);
      }
    }
  }

  cout << best << endl;
}