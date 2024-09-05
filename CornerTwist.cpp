#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid1(n);
        vector<string> grid2(n);
        for (int i = 0; i < n; i++) {
            cin >> grid1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> grid2[i];
        }

        vector<int> r1(n), r2(n), c1(m), c2(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r1[i] += grid1[i][j] - '0';
                r2[i] += grid2[i][j] - '0';
                c1[j] += grid1[i][j] - '0';
                c2[j] += grid2[i][j] - '0';
            }
        }

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (r1[i] % 3 != r2[i] % 3)
                ans = false;
        }
        for (int i = 0; i < m; i++) {
            if (c1[i] % 3 != c2[i] % 3)
                ans = false;
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}