#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
private:
    vector<vector<int>> up;
    vector<int> parent;
    vector<int> visited;
    vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 20;
        parent = parent;
        up = vector<vector<int>>(n, vector<int>(LOG));
        depth = vector<int>(n);
        visited = vector<int>(n);
        parent[0] = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                depth[i] = depth[parent[i]] + 1;
            }

            up[i][0] = parent[i];
            for (int j = 1; j < LOG; j++) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }

    void dfs(int node, int d) {
        if (visited[node])
            return;

        visited[node] = true;
        
        up[node][0] = parent[node];
        for (int j = 1; j < LOG; j++) {
            dfs(parent[node], d+1);
            up[node][j] = up[up[node][j-1]][j-1];
        }
    }

    int getKthAncestor(int node, int k) {
        if (depth[node] < k) {
            return -1;
        }
        for (int i = 0; i < LOG; i++) {
            if ((1 << i) & k) {
                node = up[node][i];
            }
        }
        return node;
    }
};

int main() {
    vector<int> parent = {-1, 2, 3, 0};
    TreeAncestor tree(4, parent);
    cout << tree.getKthAncestor(2, 2);
}