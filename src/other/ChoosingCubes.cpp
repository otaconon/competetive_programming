#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        int fav_val = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        fav_val = a[f-1];
        sort(a.begin(), a.end());
        int first_idx = lower_bound(a.begin(), a.end(), fav_val) - a.begin();
        auto it = upper_bound(a.begin(), a.end(), fav_val);
        it--;
        int last_idx = it - a.begin();

        first_idx = n - first_idx - 1;
        last_idx = n - last_idx - 1;

        if (first_idx < k) {
            cout << "YES" << endl;
        }
        else if (first_idx >= k && last_idx < k) {
            cout << "MAYBE" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}