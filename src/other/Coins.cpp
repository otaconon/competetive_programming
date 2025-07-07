#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        double p_heads = p[i], p_tails = 1 - p[i];

        dp[0][i] = p_tails * dp[0][i-1];
        for (int heads = 1; heads <= i; heads++) {
            dp[heads][i] = p_heads * dp[heads-1][i-1] + p_tails * dp[heads][i-1];
        }
    }

    double ans = 0;
    for (int i = n/2 + 1; i <= n; i++) {
        ans += dp[i][n];
    }

    cout << setprecision(9) << ans << endl;
}