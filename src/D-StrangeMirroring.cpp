#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int q;
  cin >> s;
  cin >> q;

  int n = s.size();
  while (q--) {
    long long k;
    cin >> k;
    k--;

    long long x = k / n + 1;
    long long y = k % n;
    
    bool flip = false;
    while (x > 1) {
      long long whole = 1;
      while (whole < x) whole <<= 1;
      long long middle_left = whole / 2;
      x = x - middle_left;

      flip = !flip;
    }

    if (flip)
      cout << (s[y] < 97 ? char(s[y] + 32) : char(s[y] - 32)) << ' ';
    else
      cout << s[y] << ' ';
    
  }
}