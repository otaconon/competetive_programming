#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9+7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(k+1);
    vector<int> s(k+1);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        d[0] = s[0] = 1;
        for (int j = 1; j <= k; j++) {
            s[j] = s[j-1] + d[j];
            s[j] %= MOD;
        }
        for (int j = 1; j <= k; j++) {
            d[j] = s[j];
            if (a < j) {
                d[j] = (d[j] + MOD - s[j - a - 1]) % MOD;
            }
        }
    }

    cout << d[k] << endl;
}