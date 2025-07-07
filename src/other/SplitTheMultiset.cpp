#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int u = n;
        int ans = 0;
        while (u > 1) {
            u -= (k-1);
            ans++;
        }

        cout << ans << endl;
    }
}