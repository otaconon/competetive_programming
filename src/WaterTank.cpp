#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += h[i];
        cout << ans + 1 << ' ';
    }
}