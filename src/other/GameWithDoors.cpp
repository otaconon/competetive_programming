#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        int L, R;
        cin >> l >> r;
        cin >> L >> R;

        if (min(r, R) < max(l, L)) {
            cout << 1 << endl;
        }
        else {
            int ans = min(r, R) - max(l, L) + 2;
            if (r == R) {
                ans--;
            }
            if (l == L) {
                ans--;
            }

            cout << ans << endl;
        }
    }
}