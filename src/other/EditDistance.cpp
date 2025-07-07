#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    for (size_t i = 0; i <= s1.size(); i++)
        dp[i][0] = i;

    for (size_t i = 0; i <= s2.size(); i++)
        dp[0][i] = i;

    for (size_t i = 1; i <= s1.size(); i++) {
        for (size_t j = 1; j <= s2.size(); j++) {
            int cost = s1[i-1] == s2[j-1] ? 0 : 1;
            dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + cost));
        }
    }

    cout << dp[s1.size()][s2.size()] << endl;
}