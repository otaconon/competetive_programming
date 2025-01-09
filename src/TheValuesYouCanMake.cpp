#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto& x : c)
        cin >> x;

    int m = accumulate(c.begin(), c.end(), 0);

    vector<vector<bool>> dp(n, vector<bool>(m+1));
    dp[0][c[0]] = true;
    for (int i = 1; i < n; i++) {
        dp[i][c[i]] = true;
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j];

            if (j - c[i] < 0)
                continue;

            dp[i][j] = dp[i][j] || dp[i-1][j-c[i]];
        }
    }

    for (int i = 0; i <= m; i++) {
        if (dp[n-1][i])
            cout << i << ' ';
    }
}