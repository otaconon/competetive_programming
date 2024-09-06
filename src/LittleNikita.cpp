#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int k = n - m;
        if (k % 2 == 0 && n >= m) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}