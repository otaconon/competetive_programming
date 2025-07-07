#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        dist1.assign(n, INT_MAX);
        dist2.assign(n, INT_MAX);
        vis.resize(n);

        dfs(edges, dist1, node1, 0);
        vis.assign(n, false);
        dfs(edges, dist2, node2, 0);
        
        pair<int, int> ans = {-1, INT_MAX};
        for (int i = 0; i < n; i++) {
            int d = max(dist1[i], dist2[i]);
            if (d < ans.second)
                ans = {i, d};
        }

        return ans.first;
    }

private:
    vector<int> dist1, dist2;
    vector<bool> vis;

private:
    void dfs(vector<int>& adj, vector<int>& distances, int u, int dist) {
        if (u == -1 || vis[u])
            return;
        vis[u] = true;

        distances[u] = dist;

        dfs(adj, distances, adj[u], dist+1);
    }
};


int main() {
    vector<int> adj = {2, 2, 3, -1};
}