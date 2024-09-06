#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> W(n+1);
    vector<int> V(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }

    vector<vector<long long>> dp(n+1, vector<long long>(w+1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= w; i++) {
        if (i > W[0])
            dp[0][i] = V[0];
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (W[i] > j)
                continue;
            
            dp[i][j] = max(dp[i][j], V[i] + dp[i-1][j - W[i]]);
        }
    }

    cout << dp[n][w] << endl;
}