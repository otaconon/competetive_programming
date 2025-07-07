#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a != b) {
        if ((a % 2) != (b % 2)) {
            cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }
    else {
        cout << 1 << endl;
    }
}