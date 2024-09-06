#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return -0.25*x*x + x + 2;
}

double mz(double eps) {
    double a = 2.0;
    double b = 10.0;
    double c = 10;

    while (abs(f(c)) > eps) {
        c = (a + b) / 2;

        cout << f(abs(b-a)) << '\n';
        cout << "a: " << a << "   b: " << b << '\n';
        cout << f(c) << '\n';
        if (f(c) > 0)
            a = c;
        else
            b = c;
    }
    return c;
}

int main() {
    double eps, x;
    eps = 0.001;
    x = mz(eps);

    cout << "Miejsce zerowe: " << x << '\n';
    cout << "f(" << x << ") =" << f(x);
}