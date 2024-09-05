#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> r(n*2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long dist = 0;
    for (int i = 0; i < n*2; i++) {
        r[i] = dist % m;
        dist += a[i % n];
    }

    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        b[r[i]]++;
    }

    long long ans = 0;
    for (int i = n; i < n*2; i++) {
        b[r[i - n]]--;
        ans += b[r[i]];
        b[r[i]]++;
    }

    cout << ans << endl;
    
}