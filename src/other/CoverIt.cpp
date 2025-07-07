#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> selected;

int cntSelected;

void bfs(bool startBool) {
    visited = vector<bool>(n+1);
    selected = vector<bool>(n+1);
    cntSelected = 0;

    queue<pair<int, int>> bfsQueue;

    visited[1] = true;
    bfsQueue.push({1, startBool});

    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front().first;
        bool select = bfsQueue.front().second;
        bfsQueue.pop();

        if (select) {
            selected[currentNode] = true;
            cntSelected++;
        }

        for (auto neigh: adj[currentNode]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                bfsQueue.push({neigh, !select});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        
        adj = vector<vector<int>>(n+1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(true);

        if (cntSelected > n / 2) {
            bfs(false);
        }

        cout << cntSelected << '\n';

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                cout << i << ' ';
            }
        }

        cout << endl;

    }
}