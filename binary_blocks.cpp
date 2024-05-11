#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;

    int cnt = 0;
    int last_x = -1;
    while (x > 0) {
        if ((x & 1) != last_x) {
            cnt++;
            last_x = x & 1;
        }
        x /= 10;
    }

    cout << cnt << endl;
}