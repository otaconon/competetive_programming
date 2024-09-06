#include <bits/stdc++.h>

using namespace std;

constexpr int LOG = 20;

int n, q;
vector<vector<int>> up;

void precompute() {
    for (int l = 1; l < LOG; l++) {
        for (int i = 1; i < n; i++) {
            if (up[i][l-1] == -1) {
                up[i][l] = -1;
                continue;
            }

            up[i][l] = up[up[i][l-1]][l-1];
        }
    }
}

int main() {
    cin >> n >> q;
    up.resize(n, vector<int>(LOG));
    for (int l = 0; l < LOG; l++) {
        up[0][l] = -1;
    }
    
    for (int i = 1; i < n; i++) {
        cin >> up[i][0];
        up[i][0]--;
    }

    precompute();

    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;

        int ans = 0;
        for (int l = 0; l < LOG; l++) {
            if ((1 << l) & k) {
                if (up[x][l] == -1) {
                    ans = -1;
                    break;
                }
                x = up[x][l];
                ans = x+1;
            }
        }

        cout << ans << endl;
    }
}