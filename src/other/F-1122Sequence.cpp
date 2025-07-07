#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  vector<vector<int>> dp(n, vector<int>(2));
  vector<int> last(21, -1);

  last[a[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (last[a[i]] == -1) {
      last[a[i]] = i;
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][1] = -1;
      continue;
    }

    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = dp[last[a[i]]][0] + 1;
    last[a[i]] = i;
  }

  cout << max(dp[n-1][0], dp[n-1][1]) * 2;
}