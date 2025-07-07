#include <bits/stdc++.h>

struct ModInt
{
	int v;
	static const int m = 998244353;

	ModInt(int v = 0)
	{
		this->v = ((v % m) + m) % m;
	}

	operator int() const
	{
		return v;
	}

	ModInt& operator=(const int rhs)
	{
        v = ((rhs % m) + m) % m;
		return *this;
	}

	ModInt& operator+=(const ModInt& rhs)
	{
		v = (v + rhs.v) % m;
		return *this;
	}

	ModInt& operator-=(const ModInt& rhs)
	{
		v = (v - rhs.v + m) % m;
		return *this;
	}

	ModInt& operator*=(const ModInt& rhs)
	{
		v = (int)(((long long)v * rhs.v) % m + m) % m;
		return *this;
	}

	ModInt pow(int exponent) const
	{
		ModInt result(1);
		ModInt base(v);
		while (exponent > 0)
		{
			if (exponent % 2 == 1)
				result *= base;
			base *= base;
			exponent /= 2;
		}
		return result;
	}

	ModInt inv() const
	{
		return pow(m - 2);
	}

	ModInt& operator/=(const ModInt& rhs)
	{
		*this *= rhs.inv();
		return *this;
	}

	friend ModInt operator+(ModInt lhs, const ModInt& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	friend ModInt operator-(ModInt lhs, const ModInt& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	friend ModInt operator*(ModInt lhs, const ModInt& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	friend ModInt operator/(ModInt lhs, const ModInt& rhs)
	{
		lhs /= rhs;
		return lhs;
	}
};

using namespace std;

constexpr int mod = 998244353;

using ll = long long;
using mint = ModInt;

vector<mint> fac, inv, facinv;
void modcalc(int n = 3000) {
    fac.resize(n); inv.resize(n); facinv.resize(n);
    fac[0] = facinv[0] = inv[1] = fac[1] = facinv[1] = 1;

    for (int i = 2; i < n; ++i) {
        fac[i] = fac[i - 1] * mint(i);
        inv[i] = inv[mod % i] * mint(mod - mod / i);
        facinv[i] = facinv[i - 1] * inv[i];
    }
}

mint comb(int n, int k) {
    if (n < 0 || k < 0 || n < k) return mint();
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

    mint ans;
    for (int j = 1; j <= k; j++) {
        ans += dp[26][j];
    }

    cout << ans.v << endl;
}