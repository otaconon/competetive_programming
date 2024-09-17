#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> x(n);
    set<int> lx, rx;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (s[i] == '0') {
            lx.insert(x[i]);
        }
        else {
            rx.insert(x[i]);
        }
    }

    long long ans = 0;
    for (auto it_r = rx.begin(); it_r != rx.end(); it_r++) {
        auto first = lx.lower_bound(*it_r);
        auto second = lx.lower_bound(*it_r + t);

        ans += distance(first, second);
    }

    cout << ans << endl;
}