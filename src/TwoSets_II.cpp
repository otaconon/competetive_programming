#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;

    int sum = n*(n + 1)/2;
    if (sum % 2) {
        cout << 0 << '\n';
        return 0;
    }
    
    sum /= 2;

    vector<vector<int>> dp(sum+1, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= sum; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j-1];
            if (i - j >= 0) {
                dp[i][j] += dp[i - j][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[sum][n-1] << endl;
}