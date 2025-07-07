#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;

  int ans = 0;
  for (auto& c : s)
    if (c == '.')
      ans++;

  cout << ans + d << endl;
}