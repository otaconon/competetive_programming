#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<int> b(n);
        vector<pair<long long, int>> c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            c[i] = {a[i], b[i]};
        }

        sort(c.begin(), c.end());

        vector<long long> psum(n);
        psum[0] = c[0].first;
        for (int i = 1; i < n; i++) {
            psum[i] = psum[i-1] + c[i].first;
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long median = 0;
            int p = ((n+1)/2)-1;
            if (n % 2) {
                if (i < p) {
                    median = p;
                }
                else {
                    median = p-1;
                }
            }
            else {
                if (i <= p) {
                    median = p+1;
                }
                else {
                    median = p;
                }
            }

            if (c[i].second) {
                ans = max(ans, c[median].first + c[i].first + k);
            }
            if (c[median].second) {
                long long lo = c[median].first, hi = c[median].first + k+1;
                while (lo < hi) {
                    long long mid = (lo + hi + 1) / 2;
                    long long x = psum[n-1] - psum[median-1];
                    int y = n;
                    if (i > median) {
                        x -= c[i].first;
                        y--;
                    }
                    long long ops = mid * (y - median) - x;

                    if (ops <= k) {
                        lo = mid;
                    }
                    else {
                        hi = mid - 1;
                    }
                }

                ans = max(ans, c[i].first + lo);
            }
            
            ans = max(ans, c[i].first + c[median].first);
        }

        cout << ans << endl;
    }
}