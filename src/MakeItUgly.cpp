#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int>& a) {
    int prev = -2;
    int ans = INT_MAX;
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++)
        if (a[i] != a[0]) last = i;
    for (int i = n-1; i >= 0; i--)
        if (a[i] != a[0]) first = i;

    if (first == -1)
        return -1;
    else if (first == last)
        return min(first, n - first - 1);

    prev = first;
    for (int i = first+1; i < n; i++) {
        if (a[i] != a[0]) {
            ans = min(ans, i - prev - 1);
            prev = i;
        }
    }

    return min(ans, min(first, n - last -1));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sol = solve(n, a);

        cout << sol << endl;
    }
}