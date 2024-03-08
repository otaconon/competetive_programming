#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> adj;
vector<vector<bool>> visited;

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || adj[r][c] == '#') return;

    visited[r][c] = true;

    floodfill(r-1, c);
    floodfill(r+1, c);
    floodfill(r, c-1);
    floodfill(r, c+1);
}

int main() {
    cin >> n >> m;
    visited.resize(n, vector<bool>(m));
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }

    int color = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (!visited[r][c] && adj[r][c] != '#') {
                floodfill(r, c);
                color++;
            }
        }
    }

    cout << color << endl;
}