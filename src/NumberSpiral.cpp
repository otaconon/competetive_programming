#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long r, c;
        cin >> r >> c;

        long long maxi = max(r, c);
        long long square = (maxi - 1) * (maxi - 1);
        if (maxi % 2) {
            if (c > r) {
                cout << (maxi * maxi) - r + 1 << '\n';
            }
            else {
                cout << square + c << '\n';
            }
        }
        else {
            if (c > r) {
                cout << square + r << endl;
            }
            else {
                cout << (maxi * maxi) - c + 1 << endl;
            }
        }
    }
}