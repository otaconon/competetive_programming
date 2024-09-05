#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c > b) {
        if (a < b || a > c) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        if (a > c && a < b) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}