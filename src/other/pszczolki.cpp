#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> dp(n+1);
  dp[0] = {1, 0};
  for (int i = 1; i <= n; i++) {
    dp[i].first = (dp[i-1].first + dp[i-1].second) % mod;
    dp[i].second = dp[i-1].first % mod;
  }

  cout << dp[n].second << '\n';
}