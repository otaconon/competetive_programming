#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e8;

int modAdd(int x, int y) {
    return (x % MOD + y % MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            sum += modAdd(a[i], a[j]);
        }
    }

    cout << sum << endl;
}