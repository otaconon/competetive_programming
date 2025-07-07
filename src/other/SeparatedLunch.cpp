#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    const int total_masks = 1 << 20;

    
    ll ans = LLONG_MAX;
    for (int i = 0; i < total_masks; ++i) {
        ll A = 0, B = 0;
        std::bitset<20> bitmask(i);
        for (int j = 0; j < n; j++) {
            if (bitmask[j]) {
                A += a[j];
            }
            else {
                B += a[j];
            }
        }
        ans = min(ans, max(A, B));
    }

    cout << ans << endl;
}