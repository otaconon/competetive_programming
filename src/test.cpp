#include <bits/stdc++.h>
#include "all_combined.h"

using namespace std;
using Fp = atcoder::modint998244353;
using i64 = long long;

int main() {
    i64 n;
    int k;
    cin >> n >> k;

    const Fp p = Fp(2 * (n - 1)) / Fp(n).pow(2);
    const Fp q = Fp(2) / Fp(n).pow(2);
    Fp d = 1;
    for (int i = 0; i < k; ++i) {
        d = (1 - q - p) * d + q;
    }

    const Fp u = Fp(n + 2) / 2;
    const Fp h = (1 - d);
    cout << (d + u * h).val() << endl;
}