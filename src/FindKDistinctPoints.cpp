#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;

        vector<pair<int, int>> ans;
        for (int x = 1; x < (k/2)+1; x++) {
            ans.push_back({xc + x, yc + x});
            ans.push_back({xc - x, yc - x});
        }

        if (k % 2) {
            ans.emplace_back(xc, yc);
        }

        for (auto [x, y] : ans) {
            cout << x << ' ' << y << endl;
        }
    }
}