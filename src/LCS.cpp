#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for (size_t i = 1; i <= s1.size(); i++) {
        for (size_t j = 1; j <= s2.size(); j++) {
            int same = s1[i-1] == s2[j-1] ? 1 : 0;
            dp[i][j] = max(dp[i-1][j-1] + same, max(dp[i][j-1], dp[i-1][j]));
        }
    }

    string ans = "";
    size_t i = s1.size(), j = s2.size();
    while (i && j) {
        if (s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--, j--;
        }
        else if (dp[i-1][j] < dp[i][j-1]) {
            j--;
        }
        else {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}