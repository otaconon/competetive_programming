#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();
        
        auto id2rc = [&](int id) -> pair<int,int> {
            int r = n - 1 - id / n;
            int c = id % n;
            if ((n - 1 - r) & 1)
                c = n - 1 - c;
            return {r, c};
        };
        
        vector<int> dist(n * n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == n * n - 1)
                return dist[cur];
            
            for (int d = 1; d <= 6 && cur + d < n * n; ++d) {
                int nxt = cur + d;
                
                auto [r, c] = id2rc(nxt);
                if (board[r][c] != -1)
                    nxt = board[r][c] - 1;
                
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        return -1;
    }
};
int main() {

}