#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> tree1, tree2;

int get_furthest(int node, vector<vector<int>>& tree) {
    queue<int> q;
    q.push(node);
    vector<bool> visited(tree.size());
    int furthest = node;
    while (!q.empty()) {
        int cNode = q.front();
        furthest = cNode;
        q.pop();
        visited[cNode] = true;
        for (int child : tree[cNode]) {
            if (!visited[child]) {
                q.push(child);
            }
        }
    }

    return furthest;
}

int get_distance(int node, int dest, int depth, vector<vector<int>>& tree, vector<bool>& vis) {
    if (node == dest) {
        return depth;
    }

    if (vis[node]) {
        return -1;
    }

    vis[node] = true;

    for (int child : tree[node]) {
        int dist = get_distance(child, dest, depth+1, tree, vis);
        if (dist != -1) {
            return dist;
        }
    }

    return -1;
}


int main()
{
	cin >> n;
	tree1.resize(n + 1);
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree1[u].push_back(v);
		tree1[v].push_back(u);
	}
	cin >> m;
	tree2.resize(m + 1);
	for (int i = 0; i < m-1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree2[u].push_back(v);
		tree2[v].push_back(u);
	}

	int a = get_furthest(1, tree1);
	int b = get_furthest(a, tree1);

	int c = get_furthest(1, tree2);
	int d = get_furthest(c, tree2);
	
	vector<bool> vis1(n+1);
	vector<bool> vis2(m+1);
	int d1 = get_distance(a, b, 0, tree1, vis1);
	int d2 = get_distance(c, d, 0, tree2, vis2);
	int new_d = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

	// int m1 = get_middle(tree1, a, b, d1);
	// int m2 = get_middle(tree2, c, d, d2);

	cout << max(max(d1, d2), new_d) << endl;

}