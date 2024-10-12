#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (auto& row : g)
        cin >> row;

    for (int i = 0; i < n/2; i++) {
        vector<string> cp = g;
        for (int x = i; x < n-i; x++) {
            for (int y = i; y < n-i; y++) {
                g[y][n-x-1] = cp[x][y];
            }
        }
    }

    for (auto& row : g) {
        cout << row << endl;
    }
}