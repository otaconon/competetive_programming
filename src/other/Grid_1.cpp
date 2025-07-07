#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7; 

int main() {
    int h, w;
    cin >> h >> w;
    
    vector<vector<bool>> g(h, vector<bool>(w));
    for (int row = 0; row < h; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < w; col++) {
            g[row][col] = s[col] == '.' ? true : false; 
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            if (!g[row][col]) {
                dp[row][col] = 0;
                continue;
            }
            if (row > 0)
                dp[row][col] += dp[row-1][col];
            if (col > 0)
                dp[row][col] += dp[row][col-1];

            dp[row][col] %= MOD;
        }
    }

    cout << dp[h-1][w-1] << '\n';
}