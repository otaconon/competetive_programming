#include <bits/stdc++.h>

using namespace std;

constexpr int nax = 201;

int dp[nax][nax][nax];

int main() {
    dp[0][0][0] = 0;
    for (int i = 0; i < nax; i++) {
        for (int j = 0; j < nax; j++) {
            for (int k = 0; k < nax; k++) {
                int best = 0;
                if (i) best = max(best, dp[i-1][j][k]);
                if (j) best = max(best, dp[i][j-1][k]);
                if (k) best = max(best, dp[i][j][k-1]);

                dp[i][j][k] = best;
                int xr = ((i & 1) * 1) ^ ((j & 1) * 2) ^ ((k & 1) * 3);
                if (xr == 0 && (i || j || k)) {
                    dp[i][j][k]++;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        vector<int> a(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
    
        cout << dp[a[0]][a[1]][a[2]] + a[3] / 2 << endl;
    }
    
    
}