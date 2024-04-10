#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<vector<int>> dp(n, vector<int>(m+1));
    if (values[0] != 0) {
        dp[0][values[0]] = 1;
    }
    else {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (values[i] != 0) {
            dp[i][values[i]] += dp[i-1][values[i]];
            dp[i][values[i]] %= MOD;

            if (values[i] - 1 > 0)
                dp[i][values[i]] += dp[i-1][values[i]-1];
                dp[i][values[i]] %= MOD;

            if (values[i] + 1 <= m)
                dp[i][values[i]] += dp[i-1][values[i]+1];
                dp[i][values[i]] %= MOD;

            continue;
        }

        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;

            if (j - 1 > 0)
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;

            if (j + 1 <= m)
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}
