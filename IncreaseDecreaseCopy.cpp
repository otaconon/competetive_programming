#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n+1);
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n+1; i++) {
            cin >> b[i];
        }

        long long ans = 1;
        bool handled = false;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i] - b[i]);
            if (b[n] >= min(a[i], b[i]) && b[n] <= max(b[i], a[i])) {
                handled = true;
            }
            else {
                mn = min(mn, min(abs(a[i] - b[n]), abs(b[i] - b[n])));
            }
        }

        if (!handled)
            ans += mn;

        cout << ans << endl;
    }
}