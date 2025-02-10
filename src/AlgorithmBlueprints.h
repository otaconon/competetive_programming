#include <bits/stdc++.h>

using namespace std;

struct LCA {
    int n, l;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    LCA(int n, int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l+1));
        dfs(root, root);
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
};

class DSU {
private:
    vector<int> parents;
    vector<int> sizes;

public:
    DSU(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }

    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }

        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

struct SCC {
    vector<bool> visited;
    vector<vector<int>> adj;
    vector<int> output;
    vector<vector<int>> components;
    vector<vector<int>> adj_cond;

    void dfs(int v) {
        visited[v] = true;
        for (auto u : adj[v])
            if (!visited[u])
                dfs(u);
        output.push_back(v);
    }

    void strongly_connected_components() {
        int n = adj.size();
        components.clear(), adj_cond.clear();

        vector<int> order; // will be a sorted list of G's vertices by exit time

        visited.assign(n, false);

        // first series of depth first searches
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i);

        // create adjacency list of G^T
        vector<vector<int>> adj_rev(n);
        for (int v = 0; v < n; v++)
            for (int u : adj[v])
                adj_rev[u].push_back(v);

        visited.assign(n, false);
        reverse(order.begin(), order.end());

        vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

        // second series of depth first searches
        for (auto v : order)
            if (!visited[v]) {
                std::vector<int> component;
            dfs(v);
            components.push_back(component);
            int root = *min_element(begin(component), end(component));
            for (auto u : component)
                roots[u] = root;
            }

        // add edges to condensation graph
        adj_cond.assign(n, {});
        for (int v = 0; v < n; v++)
            for (auto u : adj[v])
                if (roots[v] != roots[u])
                    adj_cond[roots[v]].push_back(roots[u]);
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<int> t;

    SegmentTree(int n, vector<int>& vec) {
        t.resize(n*4);
        a = vec;
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};