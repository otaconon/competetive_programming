#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(1e5+1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 1e5; j++) {
            if (dp[i-1][j])
                dp[i][j] = true;
            else if (j - coins[i] >= 0)
                if (dp[i-1][j - coins[i]])
                    dp[i][j] = true;
                
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= 1e5+1; i++) {
        if (dp[n][i]) cnt++;
    }
    cout << cnt << '\n';

    for (int i = 1; i <= 1e5+1; i++) {
        if (dp[n][i])
            cout << i << ' ';
    }
}