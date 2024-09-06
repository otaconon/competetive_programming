#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7;

int n;
vector<vector<int>> dp;
vector<vector<bool>> grid;

int main() {
    cin >> n;
    dp.resize(n, vector<int>(n));
    grid.resize(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (size_t j = 0; j < s.size(); j++) {
            if (s[j] == '.')
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) dp[i][j] = 0;
            else {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;

}