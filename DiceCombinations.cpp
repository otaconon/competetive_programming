#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> count(n+1);
    count[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (x - dice >= 0) {
                count[x] += count[x - dice];
                count[x] %= MOD;
            }
        }
    }

    cout << count[n] << '\n';
}