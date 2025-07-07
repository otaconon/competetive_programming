#include <bits/stdc++.h>

using namespace std;

int PositionRightmostSetbit(int n)
{
    int p = 1;

    while (n > 0) {
        if (n & 1) {
            return p;
        }
        p++;
        n = n >> 1;
    }
    return -1;
}
 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        long long r = x ^ y;

        long long lsb = PositionRightmostSetbit(r);

        cout << std::fixed << std::setprecision(0) << pow(2, lsb - 1) << endl;
    }
}