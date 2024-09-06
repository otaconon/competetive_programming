#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> point(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int gift;
            cin >> gift;
            gift--;
            adj[i].push_back(gift);
        }

        while (adj[i].back() != i) {
            adj[i].pop_back();
        }
    }

    vector<int> ans(n);
    vector<vector<bool>> visited(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        
        vector<int> s;

        s.push_back(i);
        int start = i;
        
        while (!s.empty()) {
            int node = s.back();
            s.pop_back();

            if (visited[i][node]) continue;
            visited[i][node] = true;

            for (auto neigh: adj[node]) {
                s.push_back(neigh);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int g: adj[i]) {
            if (visited[g][i]) {
                cout << g + 1 << '\n';
                break;
            }
        }
    }
}