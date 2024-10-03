#include <bits/stdc++.h>

#include "all_combined.h"
#include "ModInt.h"

using namespace std;
using namespace atcoder;

constexpr int mod = 998244353;

using ll = long long;
using mint = static_modint<mod>;

vector<mint> fac, inv, facinv;
void modcalc(int n = 3000) {
    fac.resize(n); inv.resize(n); facinv.resize(n);
    fac[0] = 1; fac[1] = 1; inv[1] = 1;
    facinv[0] = 1; facinv[1] = 1;

    for (ll i = 2; i < n; i++) {
        fac[i] = fac[i-1] * i;
        inv[i] = -inv[mod % i] * (mod / i);
        facinv[i] = facinv[i - 1] * inv[i];
    }
}

mint comb(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] * facinv[n - k];
}

int main() {
    int k;
    cin >> k;
    vector<int> c(26);
    for (auto& x : c) cin >> x;

    modcalc();

    vector<vector<mint>> dp(27, vector<mint>(k+1));
    dp[0][0] = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < k+1; j++) {
            for (int l = 0; l < min(j, c[i]) + 1; l++) {
                dp[i+1][j] += dp[i][j-l] * comb(j, l);
            }
        }
    }

    mint ans = 0;
    for (int j = 1; j <= k; j++) {
        ans += dp[26][j];
    }

    cout << ans.val() << endl;
}