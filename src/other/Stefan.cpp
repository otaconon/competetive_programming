#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);

    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    vector<long long> p1(n);
    p1[0] = a[0];
    for (int i = 1; i < n; i++) {
        p1[i] = p1[i-1] + a[i];
    }

    vector<long long> neg1;
    for (int i = 0; i < n; i++) {
        if (p1[i] < 0)
            neg1.push_back(i);
    }

    vector<long long> p2(n);
    p2[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        p2[i] = p2[i+1] + a[i];
    }

    vector<long long> neg2;
    for (int i = 0; i < n; i++) {
        if (p2[i] < 0)
            neg2.push_back(i);
    }

    long long ans = 0;
    long long max_l = 0;
    for (int l = 0, r = 0; l < neg1.size() && r < neg2.size(); r++) {
        if (neg2[r] > neg1[l]) {
            max_l = max(max_l, abs(p1[neg1[l]]));
            l++;
        }

        ans = max(ans, s + max_l + abs(p2[neg2[r]]));
    }

    cout << ans << endl;
}