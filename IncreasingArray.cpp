#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int diff = max(a[i-1] - a[i], 0);
        ans += diff;
        a[i] += diff;
    }

    cout << ans << endl;
}