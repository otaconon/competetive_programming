#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, 1));

    vector<set<int>> col(w);
    vector<set<int>> row(h);
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            col[c].insert(r);
            row[r].insert(c);
        }
    }

    auto erase = [&](int r, int c) { row[r].erase(c), col[c].erase(r); };

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        }
        else {
            auto up = col[c].lower_bound(r);
            if (up != col[c].begin()) erase(*prev(up), c);

            auto down = col[c].lower_bound(r);
            if (down != col[c].end()) erase(*down, c);

            auto right = row[r].lower_bound(c);
            if (right != row[r].end()) erase(r, *right);

            auto left = row[r].lower_bound(c);
            if (left != row[r].begin()) erase(r, *prev(left));
        }
    }

    long long ans = 0;
    for (auto& r : row) {
        ans += r.size();
    }
    cout << ans << endl;
}