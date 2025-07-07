#include <iostream>
#include <string>
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

int main()
{
	long long n, k;
    cin >> n >> k;

    long long n_sq_inv = inv(n * n % MOD);
    long long p = 2 * (n - 1) % MOD * n_sq_inv % MOD;
    long long q = 2 * n_sq_inv % MOD;
    long long s = (1 - q - p + 2 * MOD) % MOD;

    long long dp = 1;
    for (int i = 0; i < k; ++i) {
        dp = (s * dp % MOD + q) % MOD;
    }

    long long u = (n + 2) % MOD * inv(2) % MOD;
    long long h = (1 - dp + MOD) % MOD;
    cout << (dp + u * h % MOD) % MOD << endl;
}