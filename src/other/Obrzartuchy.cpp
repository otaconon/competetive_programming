#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long day_time = 24 * 60 * 60;
        vector<int> times(n);
        for (int i = 0; i < n; i++) {
            cin >> times[i];
        }

        long long cnt = 0;
        for (auto& time : times) {
            cnt += day_time / time;
        }

        long long ans = cnt / m;
        if (cnt % m != 0) {
            ans++;
        }

        cout << ans << endl;
    }
}