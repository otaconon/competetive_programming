#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;

vector<bool> visited;
void dfs(int node) {
    if (visited[node])
        return;

    visited[node] = true;

    for (auto child : tree[node]) {
        dfs(child);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    tree.resize(n);
    visited.resize(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        p[i] = x;
    }

    for (int i = 0; i < n; i++) {
        tree[i].push_back(p[i]);
        tree[p[i]].push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << endl;
}