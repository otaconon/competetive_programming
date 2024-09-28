#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << a[n-1].first + b[n-1].first << endl;
}