#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n, 1);

        for (int i = y-2; i >= 0; i -= 2) {
            a[i] = -1;
        }
        for (int i = x; i < n; i += 2) {
            a[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }

        cout << endl;
    }
}