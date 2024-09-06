#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> a;
vector<bool> vis;
stack<int> s;
stack<int> ans;

vector<bool> on_path;
bool should_end = false;
void dfs(int node, int prev) {
    if (vis[node])
        return;

    s.push(node + 1);
    on_path[node] = true;
    vis[node] = true;

    for (int child : a[node]) {
        if (should_end)
            return;
        if (prev != -1 && child != prev && on_path[child]) {
            s.push(child + 1);
            ans = s;
            s.pop();
            should_end = true;
        }
        dfs(child, node);
    }

    on_path[node] = false;
    s.pop();
}

int main() {
    cin >> n >> m;
    a.resize(n);
    vis.resize(n);
    on_path.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, -1);
        if (should_end)
            break;
    }
    

    if (ans.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    queue<int> final;
    int end = ans.top();
    ans.pop();
    final.push(end);
    while (ans.top() != end) {
        final.push(ans.top());
        ans.pop();
    }
    final.push(ans.top());

    cout << final.size() << endl;
    while (!final.empty()) {
        cout << final.front() << ' ';
        final.pop();
    }
}