#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == c)
        cout << "NWR" << endl;
    else if (a == 0)
        cout << "BR" << endl;
    else
        cout << fixed << setprecision(2) << (c - b) / a;
}