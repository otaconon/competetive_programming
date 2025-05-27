#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        pair<int, int> ans = {0, 1};
        vector<vector<bool>> dp(n, vector<bool>(n));
        fill(dp[0].begin(), dp[0].end(), true);
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[1][i] = true;
                ans = {i, i+1};
             }
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < n-i; j++) {
                if (dp[i-2][j+1] && s[j] == s[j+i]) {
                    ans = {j, j + i};
                    dp[i][j] = true;
                }
            }
        }
        return s.substr(ans.first, ans.second);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("cbbd") << endl;
    cout << sol.longestPalindrome("aa") << endl;

    string s1 = "aab";
    cout << s1.substr(0, 1) << endl;
    cout << s1.substr(1, 2) << endl;
}