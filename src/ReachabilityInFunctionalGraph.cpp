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

// It's easy to see that we are iterating over same nodes many times.
// The problem can be solved by Finding every cycle, then all the nodes in the cycle can go to each other
// Starting a dp from leaf nodes we can iterate adding to dp

long long solve(vector<int>& vec) {
    // Create vector a, to store ingoing path, so that it is possible to iterate from leafs
    size_t n = vec.size();
    vector<vector<int>> a(n);
    stack<pair<int, int>> s;
    for (size_t i = 0; i < n; i++) {
        a[vec[i]].push_back(i);
        if (vec[i] == i)
            s.push({i, -1});
    }

    // dp to store the number of nodes it is possible to travel from node i
    // backtrack to update all the nodes visited in cycle to the value dp[cycle_end]
    vector<int> dp(n, 1);
    vector<bool> vis(n);
    stack<int> backtrack;
    while (!s.empty()) {
        auto [node, parent] = s.top();
        backtrack.push(node);
        s.pop();

        if (vis[node]) {
            int cycle = backtrack.top();
            backtrack.pop();
            while (backtrack.top() != cycle) {
                dp[backtrack.top()] = dp[cycle];
                backtrack.pop();
            }
        }

        vis[node] = true;
        dp[node] += parent != -1 ? dp[parent] : 0; 

        for (auto& child : a[node]) {
            if (child == node)
                continue;
            s.push({child, node});
        }
    }

    return std::accumulate(dp.begin(), dp.end(), 0LL);
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
    cout << solve(a) << endl;
}