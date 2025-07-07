#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> best = {0, 0};
        for (int x = 2; x <= n; x++) {
            int cnt = 0;
            for (int i = 1; x * i <= n; i++) {
                cnt += x*i;
            }
            best = cnt > best.first ? make_pair(cnt, x) : best;
        }

        cout << best.second << std::endl;
    }
}