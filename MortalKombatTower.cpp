#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(2, 1e9+5));
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int who = 0; who < 2; who++) {
                for (int fight = 1; fight <= min(n-i, 2); fight++) {
                    int hard = a[i] + (fight == 2 ? a[i + 1] : 0);
                    dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + who * hard);
                }
            }
        }

        cout << min(dp[n][0], dp[n][1]) << endl;
    }
}