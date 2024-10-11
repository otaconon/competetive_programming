#include <bits/stdc++.h>

using namespace std;

// To solve the problem using brute force we can iterate over all the nodes, and for every node
// do a dfs, ending the search if a cycle is detected or if the node we arrived at goes to itself
int brute_force(vector<int>& vec) {
    vector<int> ans(vec.size(), 1);
    for (int i = 0; i < vec.size(); i++) {
        int node = i;
        vector<bool> vis(vec.size());
        vis[i] = true;
        while (node != vec[node] && !vis[vec[node]]) {
            ans[i]++;
            node = vec[node];
            vis[node] = true;
        }
    }

    return accumulate(ans.begin(), ans.end(), 0);
}

namespace tarjan {
    vector<vector<int>> adj, adj_t;
    vector<int> order, vis, id;

    void dfs1(int v) {
        vis[v] = true;
        for (int u : adj[v]) {
            if (!vis[u]) { dfs1(u); }
        }
        order.push_back(v);
    }

    void dfs2(int x, int comp) {
        vis[x] = true;

        for (int u : adj_t[x]) {
            if (!vis[u]) { dfs2(u, comp); }
        }
        id[x] = comp;
    }

    long long solve_tarjan(vector<int>& vec) {
        size_t n = vec.size();
        
        adj.resize(n);
        adj_t.resize(n);
        id.resize(n);
        vis.resize(n);

        for (int i = 0; i < n; i++) {
		    if (!vis[i]) { dfs1(i); }
	    }

        vis.assign(n, false);
        std::reverse(begin(order), end(order));
        int comps = 0;
        for (int v : order) {
            if (!vis[v]) {
                dfs2(v, comps);
                comps++;
            }
        }
        
        for (size_t i = 0; i < n; i++) {
            adj[i].push_back(vec[i]);
            adj[vec[i]].push_back(i);
        }

        vector<int> cmp(n);
        for (int i = 0; i < n;i++) {
            cmp[id[i]]++;
        }

        vector<set<int>> con(n);
        for (int i = 0; i < n; i++) {
            con[id[i]].insert(id[i]);
            con[id[i]].insert(id[vec[i]]);
        }

        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            for (auto& x : con[id[i]]) {
                cnt[i] += cmp[x];
            }
        }

        for (auto& x : id) {
            cout << x << ' ';
        }
        cout << endl;
        return std::accumulate(cnt.begin(), cnt.end(), 0LL);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        x--;
    }

    cout << brute_force(a) << endl;
    cout << tarjan::solve_tarjan(a) << endl;
}