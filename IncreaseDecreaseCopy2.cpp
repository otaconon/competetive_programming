#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n+1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n+1; i++) {
            cin >> b[i];
        }

        int min_diff = INT_MAX;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (min(a[i], b[i]) <= b[n] && max(a[i], b[i]) >= b[n]) {
                min_diff = 0;
            }
            else {
                min_diff = min(min_diff, min(abs(a[i] - b[n]), abs(b[i] - b[n])));
            }
            ans += abs(a[i] - b[i]);
        }
        ans += min_diff + 1;

        cout << ans << endl;
    }
}