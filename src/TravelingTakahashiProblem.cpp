#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long long xc = 0, yc = 0;
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sqrt((x[i] - xc)*(x[i] - xc) + (y[i] - yc)*(y[i] - yc));
        xc = x[i];
        yc = y[i];
    }
    ans += sqrt((xc)*(xc) + (yc)*(yc));

    cout << fixed << setprecision(8) << ans << endl;
}