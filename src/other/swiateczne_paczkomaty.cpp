#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9+7;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> dp(n+1);
  dp[0] = 1;
  int window = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = window % mod;
    window = (window + dp[i]) % mod;
    if (i >= k) {
      window = (window - dp[i-k] + mod) % mod;
    }
  }

  cout << dp[n] << '\n';
}