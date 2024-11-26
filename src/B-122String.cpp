#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> a;

  for (auto& c : s) {
    a[c]++;
  }

  bool ok1 = true;
  for (int i = 1; i <= n/2; i++) {
    if (s[2*i-2] != s[2*i-1]) {
      ok1 = false;
      break;
    }
  }

  bool ok2 = true;
  for (auto& [c, cnt] : a) {
    if (cnt != 2) {
      ok2 = false;
      break;
    }
  }
  if ((n % 2 == 0) && ok1 && ok2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}