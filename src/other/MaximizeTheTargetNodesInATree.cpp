#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void paint(vector<vector<int>>& adj, vector<bool>& colors, int node, int parent) {
        colors[node] = !colors[parent];
        for (auto& u : adj[node]) {
            if (u == parent)
                continue;
            paint(adj, colors, u, node);
        }
    }

    void construct(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        adj.resize(edges.size()+1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        construct(edges1, adj1);
        construct(edges2, adj2);

        colors1.resize(adj1.size());
        colors2.resize(adj2.size());

        paint(adj1, colors1, 0, 0);
        paint(adj2, colors2, 0, 0);

        vector<int> painted1(2);
        for (auto color : colors1) {
            if (color)
                painted1[1]++;
            else
                painted1[0]++;
        }

        vector<int> painted2(2);
        for (auto color : colors2) {
            if (color)
                painted2[1]++;
            else
                painted2[0]++;
        }

        vector<int> ans(adj1.size());
        for (int i = 0; i < adj1.size(); i++) {
            ans[i] = painted1[colors1[i]] + max(painted2[0], painted2[1]);
        }

        return ans;
    }

    vector<vector<int>> adj1, adj2;
    vector<bool> colors1, colors2;
};

int main() {
    Solution sol;

    std::vector<std::vector<int>> edges1 = {
    {2, 1},
    {7, 3},
    {0, 4},
    {7, 5},
    {2, 6},
    {0, 2},
    {0, 7}
};
    std::vector<std::vector<int>> edges2 = {
    {3, 0},
    {1, 2},
    {5, 1},
    {6, 3},
    {9, 4},
    {5, 6},
    {7, 5},
    {9, 7},
    {8, 9}
};

    auto res = sol.maxTargetNodes(edges1, edges2);
    for (auto& x : res)
        cout << x << ' ';
}