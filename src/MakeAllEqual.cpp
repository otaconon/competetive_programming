#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> cnt(n+1);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, n - cnt[a[i]]);
        }

        cout << ans << endl;

    }
}