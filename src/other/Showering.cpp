#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<int> ls;
        vector<int> rs;

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            ls.push_back(l);
            rs.push_back(r);
        }

        sort(ls.begin(), ls.end());
        sort(rs.begin(), rs.end());

        bool ans = false;

        if (ls[0] >= s)
            ans = true;
        if (m - rs[n-1] >= s)
            ans = true;

        for (int i = 0; i < n-1; i++) {
            if (ls[i+1] - rs[i] >= s)
                ans = true;
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}