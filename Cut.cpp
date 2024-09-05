#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> bottom;
    vector<int> top;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i < n - k) {
            bottom.push_back(x);
        }
        else {
            top.push_back(x);
        }
    }

    top.insert(top.end(), bottom.begin(), bottom.end());
    for (auto& x : top) {
        cout << x << ' ';
    }
}