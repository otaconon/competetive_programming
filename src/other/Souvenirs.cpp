#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < a.size() && a[j] < b[i]) {
            j++;
        }

        if (j == a.size()) {
            cout << -1 << endl;
            return 0;
        }

        ans += a[j];
        j++;
    }

    cout << ans << endl;
}