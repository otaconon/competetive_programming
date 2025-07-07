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