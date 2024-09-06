#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);

    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    long long ans = 0;

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i];
        ans = max(ans, cnt);
        if (cnt < 0) {
            cnt = 0;
        }
    }

    cout << ans << endl;
}