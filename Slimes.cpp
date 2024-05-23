#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ps(n+1);
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + a[i-1];
    }
    
    for (int i = 2; i <= n; i++) {
        int last = 0;
        for (int l = 1, r = i; r <= n; l++, r++) {
            int s1 = ps[r-1] - ps[l-1];
            int s2 = ps[r] - ps[l];

            dp[i][l] = min(dp[i-1][l] + s1 + a[r-1], dp[i-1][l+1] + s2 + a[l-1]);
            last = l;
        }

        for (int j = last+1; j <= n; j++) {
            dp[i][j] = INT_MAX;
        }
        
        for (int r = n, l = r-i+1; l >= 1; l--, r--) {
            int s1 = ps[r-1] - ps[l-1]; //excludes the right value
            int s2 = ps[r] - ps[l]; //excludes the left value

            dp[i][r] = min(dp[i][r], min(dp[i-1][r] + s2 + a[l-1], dp[i-1][r-1] + s1 + a[r-1]));
        }
    }

    cout << dp[n][1] << endl;
}