#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (auto& x : h) cin >> x;

    if (m < h[0]) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (m - h[i] < 0) {
            cout << i << endl;
            return 0;
        }
        m -= h[i];
    }

    cout << n << endl;
}