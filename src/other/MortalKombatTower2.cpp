#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        
        // dp[i][0] - we fight the i-th boss, dp[i][1] our friend fights i-th boss
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX/2));
        dp[0][1] = a[0] == 1 ? 1 : 0;
        for (int i = 1; i < n; i++) {
            int x = i-2 >= 0 ? dp[i-2][0] : 0;
            dp[i][1] = min(x + a[i-1], dp[i-1][0] ) + a[i];

            x = i-2 >= 0 ? dp[i-2][1] : INT_MAX/2;
            dp[i][0] = min(x, dp[i-1][1]);
        }

        cout << min(dp[n-1][0], dp[n-1][1]) << endl;
    }
}