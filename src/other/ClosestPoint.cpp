#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (a.size() >= 3) {
            cout << "NO" << endl;
        }
        else {
            if ((a[1] - a[0]) <= 1) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }

        }
    }
}