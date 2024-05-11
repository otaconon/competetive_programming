#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> in(n+1);
    vector<set<int>> out(n+1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        out[x].insert(y);
        in[y].insert(x);
    }

    queue<int> leafs;
    for (int i = 1; i <= n; i++) {
        if (out[i].size() == 0) {
            leafs.push(i);        
        } 
    }

    int ans = 0;
    vector<int> dp(n+1, 0);

    while (!leafs.empty()) {
        int current = leafs.front();
        leafs.pop();

        for (auto parent : in[current]) {
            dp[parent] = max(dp[parent], dp[current] + 1);
            out[parent].erase(current);
            
            if (out[parent].size() == 0) {
                leafs.push(parent);
            }
        }
    }

    for (auto x : dp) {
        ans = max(ans, x);
    }

    cout << ans << endl;
}