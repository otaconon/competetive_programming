#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> a;

vector<ll> dp;
vector<ll> ans;
void dfs1(int node, int parent, ll depth) {
    ans[1] += depth;
    dp[node] = 1;
    for (int child : a[node]) {
        if (child != parent) {
            dfs1(child, node, depth+1);
            dp[node] += dp[child];
        }
    }
}

void dfs2(int node, int parent) {
    for (int child : a[node]) {
        if (child != parent) {
            ans[child] = ans[node] + n - 2 * dp[child];
            dfs2(child, node);
        }
        
    }
}

int main() {
    cin >> n;
    a.resize(n+1);
    dp.resize(n+1);
    ans.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs1(1, -1, 0);
    dfs2(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}