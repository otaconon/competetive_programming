#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 1e9+7;

int main(){
    int m = 1000000;
    vector<vector<long long>> dp(2, vector<long long>(m));
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i-1] * 2 + dp[1][i-1] * 1;
        dp[1][i] = dp[0][i-1] * 1 + dp[1][i-1] * 4;

        dp[0][i] %= MOD;
        dp[1][i] %= MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << (dp[0][n-1] + dp[1][n-1]) % MOD << endl;
    }
}