#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct process {
    int a, p, b, q;
};

int main() {
    ll n, x;
    cin >> n >> x;
    vector<process> a(n);
    for (auto& p : a)
        cin >> p.a >> p.p >> p.b >> p.q;

    ll l = 0, r = 1e10;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        ll rem = x;

        bool valid = true;
        for (int i = 0; i < n; i++) {
            process b = a[i];
            if (b.p > b.q) {
                swap(b.a, b.b);
                swap(b.p, b.q);
            }
            ll fit = x / b.p; // if filling with a, how many a's fit
            ll cost = fit * b.p; // cost of filling with a
            ll prod = fit * b.a;
            // Now try replacing some a's with b's to see if it is possible to get a better result
            while (cost - b.p + b.q < x) {
                if (prod >= mid) {
                    break;
                }
                cost -= b.p;
                cost += b.q;
                prod -= b.a;
                prod += b.b;
            }

            if (cost > x || prod < mid) {
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