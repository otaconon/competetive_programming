#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    int l = 0, r = n-1;
    while (l <= r) {
        int sum = a[r];
        while (sum + a[l] <= 4) {
            sum += a[l];
            l++;
        }
        cnt++;
        r--;
    }

    cout << cnt << endl;
}