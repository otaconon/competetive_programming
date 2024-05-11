#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (x < y) {
        if (z > x && z < y) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        if (z < x && z > y) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}