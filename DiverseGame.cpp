#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
            rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
        }
        rotate(a.begin(), a.begin() + 1, a.end());

        if (n == 1 && m == 1) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
}