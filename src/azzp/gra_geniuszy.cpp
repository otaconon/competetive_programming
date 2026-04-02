#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a.resize(n, vector<int>(n));
  for (auto& r : a)
    for (auto& c : r)
      cin >> c;

  int ans = 0;
  for (int r = 0; r < n; r++) {
    int mn = INT_MAX;
    for (int c = 0; c < n; c++) {
      mn = min(mn, a[r][c]);
    }
    ans = max(ans, mn);
  }

  cout << ans << '\n';
}