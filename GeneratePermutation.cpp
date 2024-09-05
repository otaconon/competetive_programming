#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i+1;
        }

        for (int i = 0; i+1 < n; i+=2) {
            swap(a[i], a[i+1]);
        }
        if (n % 2 == 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}