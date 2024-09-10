#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1][n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                a[i][j][k] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     pref[i] = pref[i-1] + a[i];
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    //     }
    // }

    int pref[n+1][n+1][n+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                pref[i][j][k] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                pref[i][j][k] = a[i][j][k] + a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1] + a[i-1][j-1][k] + a[i][j-1][k-1] + a[i-1][j][k-1] - a[i-1][j-1][k-1];
            } 
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        cout << pref[rx][ry][rz] - pref[lx-1][ry][rz] - pref[rx][ly-1][rz] - pref[rx][ry][lz-1] - pref[lx-1][ly-1][rz] - 
                pref[rx][ly-1][lz-1] - pref[lx-1][ry][lz-1] + pref[lx-1][ly-1][lz-1];
        cout << endl;
    }
}