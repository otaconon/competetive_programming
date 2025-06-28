#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int offset = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            a[(p-1 + offset) % n] = x;
        }
        else if (op == 2) {
            int p;
            cin >> p;
            cout << a[(p-1 + offset) % n] << '\n';
        }
        else if (op == 3) {
            int k;
            cin >> k;
            offset += k;
            offset %= n;
        }
    }
}