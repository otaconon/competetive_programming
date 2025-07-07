#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        
        int fits = n/p;
        int r = n % p;
        if (r == 0 && fits*q != m)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
