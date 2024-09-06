#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        set<int> b_set;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int good_values = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b_set.insert(b[i]);
        }

        int m;
        cin >> m;
        vector<int> d(m);
        multiset<int> d_set;
        for (int i = 0; i < m; i++) {
            cin >> d[i];
            d_set.insert(d[i]);
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            
            if (d_set.count(b[i]) > 0) {
                d_set.extract(b[i]);
            }
            else {
                possible = false;
                break;
            }
        }

        if (possible && b_set.count(d[m-1])) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}