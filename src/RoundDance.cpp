#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& a, vector<bool>& visited,vector<int>& comp, int node, int curr_comp) {
    if (visited[node]) return;
    visited[node] = true;
    comp[node] = curr_comp;

    for (auto adj : a[node]) {
        dfs(a, visited, comp, adj, curr_comp);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<set<int>> s(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s[i].insert(--x);
            s[x].insert(i);
        }

        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            for (auto j: s[i]) {
                a[i].push_back(j);
            }
        }

        vector<bool> visited(n);
        vector<int> comp(n);
        int curr_comp = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) curr_comp++;
            dfs(a, visited, comp, i, curr_comp);
        }

        vector<bool> pairless(curr_comp + 1);
        for (int i = 0; i < n; i++) {
            if (a[i].size() == 1) {
                pairless[comp[i]] = true;
            }
        }

        int cnt = 0;
        curr_comp++;
        for (auto i: pairless) {
            if (i) cnt++;
        }

        cout << curr_comp - max(cnt, 1) + 1 << ' ' << curr_comp << endl;
    }
}