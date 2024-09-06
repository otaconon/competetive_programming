#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x+1);
    dp[0] = 1;
    for (auto coin : coins) {
        for (int i = 1; i <= x; i++) {
            if (i - coin < 0)
                continue;

            dp[i] += dp[i - coin];
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << endl;
}