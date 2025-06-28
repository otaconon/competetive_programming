#include <bits/stdc++.h>
#include <ranges>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < q; i++) {
        int b;
        cin >> b;
        if (b >= 1) {
            cout << b << ' ';
            x[b-1]++;
        }
        else {
            auto idx = ranges::distance(x.begin(), ranges::min_element(x));
            cout << idx + 1 << ' ';
            x[idx]++;
        }
    }
}