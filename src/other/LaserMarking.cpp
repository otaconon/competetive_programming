#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct line {
    double x1, y1;
    double x2, y2;
};

int main() {
    int n;
    cin >> n;
    double t, s;
    cin >> t >> s;
    
    vector<line> a(n);
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1, x2, y2};
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    ll total_masks = 1 << n;
    long double ans = LDBL_MAX;
    do {
        for (int i = 0; i < total_masks; i++) {
            long double f = 0;
            double x = 0, y = 0;
            for (int j = 0; j < n; j++) {
                int idx = ord[j];
                double x1 = a[idx].x1, y1 = a[idx].y1;
                double x2 = a[idx].x2, y2 = a[idx].y2;
                if (i & (1 << j)) {
                    swap(x1, x2);
                    swap(y1, y2);
                }

                f += sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) / t;
                f += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / s;
                x = x2; y = y2;
            }
            
            ans = min(ans, f);
        }
    } while (next_permutation(ord.begin(), ord.end()));

    cout << fixed << setprecision(10) << ans << endl;
}