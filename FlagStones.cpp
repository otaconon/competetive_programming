#include <iostream>
using namespace std;

int main()
{
    long long n, m, a, d, z, y;
    cin >> n >> m >> a;
    d = a;

    a = (n % a) != 0 ? (n / a + 1) : (n / a);
    d = (m % d) != 0 ? (m / d + 1) : (m / d);

    y = a * d;
    cout << y;
}