#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < 2) {
        cout << 1 << endl;
        return 0;
    }

    long long ans = n;
    int d = a[1] - a[0];
    int l = 0;

    for (int r = 2; r < n; r++) {
        if (a[r] - a[r-1] == d) {
            continue;
        }

        long long len = r - l;

        ans += (len)*(len - 1)/2;
        l = r-1;
        d = a[r] - a[l];
    }

    long long len = n - l;
    ans += (len)*(len - 1)/2;

    cout << ans << endl;
}