#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), w(n);
    vector<deque<int>> b(n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        b[a[i]].push_back(w[i]);
        ans += w[i];
    }

    for (int i = 0; i < n; i++) {
        sort(b[i].begin(), b[i].end());
    }

    for (int i = 0; i < n; i++) {
        if (b[i].size() >= 1)
            ans -= b[i].back();
    }

    cout << ans << endl;
}