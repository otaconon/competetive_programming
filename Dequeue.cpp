#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n+1, vector<long long>(n+1));
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                dp[l][r] = a[l];
            }
            else {
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }

    cout << dp[0][n-1] << endl;
}