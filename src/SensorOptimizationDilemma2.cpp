#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
    ll n, x;
    cin >> n >> x;
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];

        if (a[i] * q[i] < b[i] * p[i]) {
            swap(a[i], b[i]);
            swap(p[i], q[i]);
        }
    }

    ll l = 0, r = 1e10;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        bool valid = true;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            ll now = LLONG_MAX;
            for (ll j = 0; j <= a[i]; j++) {
                ll k = max(mid - b[i] * j, 0LL);
                k = (k + a[i] - 1) / a[i];
                now = min(now, q[i] * j + (ll)p[i] * k);
            }
            cost += now;
            if (cost > x) {
                valid = false;
                break;
            }
        }

        if (valid)
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << endl;
}