#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
void dfs(int v, int p, vector<int>& dist) {
    if (p != -1) dist[v] = dist[p] + 1;
    for (int child : tree[v]) {
        if (child != p) {
            dfs(child, v, dist);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        tree.assign(n, vector<int>(0));
        vector<int> marked(k);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x--;
            marked[i] = x;
        }

        for (int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        if (k == 1) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> d1(n);
        dfs(marked[0], -1, d1);
        int mx = marked[0];
        for (int x : marked) {
            if (d1[x] > d1[mx]) mx = x;
        }

        vector<int> d2(n);
        dfs(mx, -1, d2);
        mx = marked[0];
        for (int x : marked) {
            if (d2[x] > d2[mx]) mx = x;
        }

        cout << (d2[mx] + 1) / 2 << endl;

    }
}