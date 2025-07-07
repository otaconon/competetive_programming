#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> xp;
    vector<int> x(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        xp[x[i]] = p[i];
    }

    map<int, long long> pref;
    pref[-1e9-1] = 0;
    long long last = 0;
    for (int i = 0; i < n; i++) {
        pref[x[i]] = last + p[i];
        last = pref[x[i]];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        long long rVal = 0, lVal = 0;
        
        auto it = pref.upper_bound(r);
        it--;
        rVal = (*it).second;

        it = pref.lower_bound(l);
        if (it == pref.end()) {
            lVal = rVal;
        }
        else {
            it--;
            lVal = (*it).second;
        }

        cout << rVal - lVal << endl;
    }
}