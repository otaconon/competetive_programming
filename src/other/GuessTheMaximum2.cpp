#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int k = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int l = 0, r = 1; r < n; l++, r++) {
            k = min(k, max(a[l], a[r]) - 1);
        }

        cout << k << endl;
    }
}