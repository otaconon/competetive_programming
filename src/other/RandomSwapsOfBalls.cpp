#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 998244353;

long long mod_pow(long long x, long long y, long long m) {
    long long res = 1;

    x = x % m;

    if (x == 0) {
        return 0;
    }

    while (y > 0) {
        if (y % 2) {
            res = (res * x) % m;
        }

        y = y >> 1;
        x = (x * x) % m;
    }

    return res;
}

long long inv(long long a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

int main() {
    long long n, k;
    cin >> n >> k;

    long long p = ((2*(n-1)) % MOD) * inv((n*n) % MOD);
    long long q = 2 * inv((n*n) % MOD);
    
    p %= MOD;
    q %= MOD;

    long long dp = 1;
    for (int i = 0; i < k; i++) {
        long long a = (1 - q + MOD) % MOD;
        dp = (((a - p + MOD) % MOD) * dp) % MOD + q;
        dp %= MOD;
    }

    long long x = (((n + 2) % MOD) * inv(2)) % MOD;
    long long f = (1 - dp + MOD) % MOD;
    long long z = (x * f) % MOD;
    cout << (dp + z) % MOD << endl;
}