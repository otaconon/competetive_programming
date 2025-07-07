#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum - a[i] + b[i]);
    }

    cout << ans << endl;
}