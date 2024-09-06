#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        long long sum = a[0];
        long long ans = 0;

        if (n == 1 && a[0] <= m)
            ans = a[0];
        
        int l = 0, r = 0;
        while (l != r || r < n-1) {
            if ((a[r] <= a[l] + 1) && (sum <= m) && r < n-1) {
                r++;
                sum += a[r];
            }
            else {
                sum -= a[l];
                l++;
            }

            if (sum <= m && a[r] <= a[l] + 1)
                ans = max(ans, sum);
        }

        cout << ans << endl;
    }
}