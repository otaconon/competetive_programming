#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto& x : c)
        cin >> x;

    vector<vector<bool>> dp(k+1, vector<bool>(k+1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= c[i]; j--) {
            for (int m = j; m >= c[i]; m--) {
                dp[j][m] = dp[j][m] || dp[j-c[i]][m-c[i]];
                dp[j][m-c[i]] = dp[j][m-c[i]] || dp[j-c[i]][m-c[i]];
            }
        }
    }

    cout << accumulate(dp[k].begin(), dp[k].end(), 0) << endl;
    for (int i = 0; i <= k; i++) {
        if (dp[k][i])
            cout << i << ' ';
    }
}