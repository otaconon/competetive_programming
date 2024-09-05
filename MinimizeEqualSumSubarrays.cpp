#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> q(n);
        q[0] = p[n-1];
        for (int i = 1; i < n; i++) {
            q[i] = p[i-1];
        }

        for (int i = 0; i < n; i++) {
            cout << q[i] << ' ';
        }
        cout << endl;
    }
}