#include <bits/stdc++.h>

using namespace std;

struct ModInt {
    int v, m;

    ModInt(int v, int m)
        : v(v),
        m(m)
    {}

    ModInt() : v(0), m(998244353) {}

    operator int() const {
        return v;
    }

    ModInt& operator=(const int rhs) {
        v = rhs % m;
        return *this;
    }

    ModInt& operator+=(const ModInt& rhs) {
        v = (v + rhs) % m;
        return *this;
    }

    friend ModInt operator+(ModInt lhs, const ModInt& rhs) {
        lhs += rhs;
        return lhs;
    }

    ModInt& operator*=(const ModInt& rhs) {
        for (int i = 0; i < rhs; i++)
            v += v;

        return *this;
    }

    friend ModInt operator*(ModInt lhs, const ModInt& rhs) {
        lhs *= rhs;
        return lhs;
    }

    ModInt inv(int x) const {
        return ModInt(x <= 1 ? x : m - (long long)(m/x) * inv(m % x) % m, m);
    }

    ModInt& operator/=(const ModInt& rhs) {
        v *= rhs.inv(rhs.v);
        return *this;
    }

    friend ModInt operator/(ModInt lhs, const ModInt& rhs) {
        lhs /= rhs;
        return lhs;
    }
};