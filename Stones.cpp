#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(k+1, -1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (auto& val : a) {
            if (i - val < 0) {
                if (dp[i] == -1)
                    dp[i] = 1;
                continue;
            }
            if (dp[i-val] == 1) {
                dp[i] = 0;
            }
            else if (dp[i] != 0) {
                dp[i] = 1;
            }
        }
    }

    if (dp[k]) {
        cout << "Second" << endl;
    }
    else {
        cout << "First" << endl;
    }

}