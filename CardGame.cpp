#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[2], b[2];
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if ((a[i] > b[j]) && (a[!i] > b[!j])) ans++;
                else if ((a[i] > b[j]) && (a[!i] == b[!j])) ans++;
                else if ((a[i] == b[j]) && (a[!i] > b[!j])) ans++;
            }
        }

        cout << ans << endl;
    }
}