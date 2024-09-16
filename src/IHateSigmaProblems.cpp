#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<vector<int>> ind(n+1);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        ind[i].push_back(0);
        ind[i].push_back(n+1);
        sort(ind[i].begin(), ind[i].end());
    }

    long long ans = (((n + 1) * n)/2) * n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ind[i].size()-1; j++) {
            long long len = ind[i][j+1] - ind[i][j] - 1;
            ans -= (((len + 1) * len)/2);
        }
    }

    cout << ans << endl;
}