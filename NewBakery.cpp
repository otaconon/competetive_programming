#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long ans = 0;
        long long l = 0, r = min(n, b);
        while (l < r) {
            int k = (l + r + 1) / 2;
            if (b - k + 1 > a) {
                l = k;
            }
            else {
                r = k-1;
            }
        }
        ans = ((2 * b + 1 - l) * l) / 2 + (n - l) * a;

        cout << ans << endl;
    }
}