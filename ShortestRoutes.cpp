#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    long long dist;
    friend bool operator<(const Node& a, const Node& b) {
        return a.dist > b.dist;
    }
};

int n, m;
vector<vector<pair<int, long long>>> a;

vector<int> vis;
vector<long long> distances;

int main() {
    cin >> n >> m;
    a.resize(n);
    vis.resize(n);
    distances.resize(n, LLONG_MAX);
    distances[0] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        a[u].emplace_back(v, d);
    }

    priority_queue<Node> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        Node cNode = pq.top();
        pq.pop();

        if (cNode.dist > distances[cNode.id])
            continue;

        for (auto child : a[cNode.id]) {
            long long new_dist = cNode.dist + child.second;
            if (distances[child.first] > new_dist) {
                pq.push({child.first, new_dist});
                distances[child.first] = new_dist;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << distances[i] << ' ';
    }
}