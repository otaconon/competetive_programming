#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> d;
vector<vector<int>> tree;
vector<int> depth;

int main() {
    vector<int> up;
    int n;
    cin >> n;
    d.resize(n, vector<int>(n));
    tree.resize(n);
    up.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        up[i] = 0;
        depth[i] = 1;
    }
    depth[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0;  j < n; j++) {
            if (i == j) {
                if (d[i][j] != 0) {
                    cout << "NO" << endl;
                    return 0;
                }
                continue;
            }
            else if (d[i][j] != d[j][i]) {
                cout << "NO" << endl;
                return 0;
            }
            int u = i, v = j;
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int k = depth[u] - depth[v];
            for (int t = 0; t < k; t++) {
                v = up[v];
            }

            while (u != v) {
                u = up[u];
                v = up[v];
            }

            if (d[i][u] == d[j][u]) {
                cout << "NO" << endl;
                return 0;
            }

            if (d[i][u] < d[j][u]) {
                up[j] = i;
                depth[j] = depth[i] + 1;
            }
            else {
                up[i] = j;
                depth[i] = depth[j] + 1;
            }
        }
    }

    cout << "YES" << endl;
}