#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N+1);
    vector<int> v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i]; 
    }

    vector<vector<int>> dp(N+1, vector<int>(1e5+1));
    for (int i = 0; i <= 1e5; i++)
        dp[0][i] = 1e9+1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 1e5; j++) {
            if (j > v[i])
                dp[i][j] = min(dp[i-1][j], w[i] + dp[i-1][j - v[i]]);
            else
                dp[i][j] = min(dp[i-1][j], w[i]);
        }
    } 

    int ans = 0;
    for (int i = 0; i <= 1e5; i++) {
        if (dp[N][i] <= W)
            ans = max(ans, i);
    }

    cout << ans << endl;
}