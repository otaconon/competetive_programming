#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<int> d(n, INT_MAX);
    vector<int> vis(n);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    d[0] = 0;

    int dest = n-1;
    while (!q.empty()) {
        int cNode = q.front();
        q.pop();

        if (cNode == dest) {
            cout << d[cNode]+1 << endl;
            stack<int> s;
            s.push(n-1);
            while (cNode != 0) {
                pair<int, int> next = {-1, INT_MAX};
                for (int child : a[cNode]) {
                    if (d[child] < next.second)
                        next = {child, d[child]};
                }
                s.push(next.first);
                cNode = next.first;
            }
            while(!s.empty()) {
                cout << s.top() + 1 << ' ';
                s.pop();
            }
            return 0;
        }

        for (int child : a[cNode]) {
            if (!vis[child]) {
                q.push(child);
                d[child] = min(d[child], d[cNode] + 1);
                vis[child] = true;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}