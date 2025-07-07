#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<long long> pows(30, 1);
    for (int i = 1; i <= 30; i++) {
        pows[i] = pows[i-1] * 2;
    }

    while (t--) {
        long long l, r;
        cin >> l >> r;

        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            if (pows[i] > r) {
                ans = i-1;
                break;
            }
        }

        cout << ans << endl;
    }
}