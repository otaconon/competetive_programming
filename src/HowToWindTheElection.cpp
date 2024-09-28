#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, long long>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        k -= a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<long long> ans(n);

    for (int i = 0; i < n; i++) {
        long long l = 0, r = 1e12+1;
        while (l < r) {
            long long mid = l + (r - l) / 2;

            auto it = upper_bound(a.begin(), a.end(), mid + a[i].first, [](const long long& value, const pair<int, long long>& p) {
                          return value < p.first;
                      });
                      
            if (it == a.end() || a.end() - it < m) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        if (l > k) {
            ans[a[i].second] = -1;
        }
        else {
            ans[a[i].second] = l;
        }
    }
    

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

}