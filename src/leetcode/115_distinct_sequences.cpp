#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9+7;

class Solution {
public:
    int numDistinct(string s, string t) {
      int n = t.size(), m = s.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1));
      for (int i = 0; i <= m; i++)
        dp[0][i] = 1;
      
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          dp[i][j] = dp[i][j-1];
          if (s[j-1] == t[i-1]) {
            dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % mod;
          }
        }
      }

      return dp[n][m];
    }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  Solution sol;
  //sol.numDistinct("babgbag", "bag");
  //sol.numDistinct("rabbbit", "rabbit");
  cout << sol.numDistinct(s1, s2) << '\n';
}