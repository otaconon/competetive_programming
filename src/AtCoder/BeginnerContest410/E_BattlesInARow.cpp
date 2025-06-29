#include <bits/stdc++.h>
#include <ranges>

using namespace std;

int main() {
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <= m; i++)
        dp[0][i] = h;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j] - a[i-1];
            if (j - b[i-1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-b[i-1]]);
        }
        if (dp[i][m] < 0) {
            cout << i-1 << '\n';
            return 0;
        }
    }

    cout << n << '\n';
}
