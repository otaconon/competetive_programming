#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n-1; i++) {
            ans = max(ans, a[i] + a[n-1]);
        }

        cout << ans << endl;
    }
}