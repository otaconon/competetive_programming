#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> pf(n+1);
    for (int i = 0; i < n; i++) {
        pf[i+1] = pf[i] + a[i];
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        cout << pf[e] - pf[s-1] << endl;
    }
}