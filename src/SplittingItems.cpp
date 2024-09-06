#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        long long ans = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                int diff = 0;
                if (k > 0) {
                    diff = max(0, prev - a[i]);
                    if (k < diff)
                        diff = k;
                    k -= diff;
                }
                
                ans -= a[i] + diff;
            }
            else {
                ans += a[i];
            }
            prev = a[i];
        }

        cout << ans << endl;
    }
}