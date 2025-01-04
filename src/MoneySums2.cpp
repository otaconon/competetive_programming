#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& c : x)
        cin >> c;

    int m = accumulate(x.begin(), x.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(m+1));
    dp[0][x[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j];

            if (j - x[i] < 0)
                continue;

            dp[i][j] = dp[i][j] || dp[i-1][j-x[i]] || j == x[i];
        }
    }

    cout << accumulate(dp[n-1].begin(), dp[n-1].end(), 0) << endl;
    for (int i = 0; i <= m; i++) {
        if (dp[n-1][i])
            cout << i << ' ';
    }
}