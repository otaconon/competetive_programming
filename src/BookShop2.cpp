#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (auto& z : h)
        cin >> z;
    for (auto& z : s)
        cin >> z;
    
    vector<vector<int>> dp(n, vector<int>(x+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (i != 0)
                dp[i][j] = dp[i-1][j];

            if (j - h[i] < 0)
                continue;
            if (i == 0) {
                dp[i][j] = s[i];
                continue;
            }
            
            dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]] + s[i]);
        }
    }

    cout << dp[n-1][x] << endl;
}