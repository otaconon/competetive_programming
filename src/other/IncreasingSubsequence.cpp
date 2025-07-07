#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (idx == dp.size())
            dp.push_back(a[i]);
        else
            dp[idx] = a[i];
    }

    cout << dp.size() << endl;
}