#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int T = 0;
  vector<pair<int, int>> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i].second >> w[i].first;
    T = max(T, w[i].first);
  }

  sort(w.begin(), w.end());

  vector<int> dp(T+1);
  for (int t = 1, j = 0; t <= T; t++) {
    dp[t] = dp[t-1];
    while (j < w.size() && w[j].first == t) {
      dp[t] = max(dp[t], dp[w[j].second] + (w[j].first) - w[j].second);
      j++;
    }
  }

  cout << dp[T] << '\n';
}