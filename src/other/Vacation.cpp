#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    vector<vector<int>> dp(n+1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i-1][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i-1][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i-1][2];
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}