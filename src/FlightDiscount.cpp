#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long u, d;

    bool operator<(const Node& v) const {
        return d > v.d;
    }
};

int n, m;
vector<vector<Node>> neigh;
vector<vector<Node>> rneigh;
vector<long long> dis1;
vector<long long> dis2;

void dijkstra(int x, vector<long long>& dis, vector<vector<Node>>& a) {
    priority_queue<Node> pq;
    pq.push({x, 0});
    dis[x] = 0;
    while (!pq.empty()) {
        Node cNode = pq.top();
        pq.pop();

        if (cNode.d > dis[cNode.u])
            continue;

        for (Node child : a[cNode.u]) {
            long long new_dist = child.d + cNode.d;
            if (new_dist < dis[child.u]) {
                dis[child.u] = new_dist;
                pq.push({child.u, dis[child.u]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    neigh.resize(n);
    rneigh.resize(n);
    dis1.resize(n, LLONG_MAX / 2);
    dis2.resize(n, LLONG_MAX / 2);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        neigh[u].push_back({v, w});
        rneigh[v].push_back({u, w});
    }

    dijkstra(0, dis1, neigh);
    dijkstra(n-1, dis2, rneigh);

    long long ans = LLONG_MAX;
    for (int u = 0; u < n; u++) {
        for (auto v : neigh[u]) {
            ans = min(ans, dis1[u] + (v.d / 2) + dis2[v.u]);
        }
    }

    cout << ans << endl;
}