#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;

    vector<int> dp(x+1, INT_MAX-1);
    dp[x] = 0;
    for (int i = x; i >= 0; i--) {
        int value = i;
        while (value) {
            int digit = value % 10;
            if (i - digit < 0)
                continue;

            dp[i - digit] = min(dp[i - digit], dp[i] + 1);

            value /= 10;
        }
    }

    cout << dp[0] << endl;
}