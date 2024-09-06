#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> lab;
vector<vector<int>> m_dist;

vector<vector<bool>> vis;

int main() {
    cin >> n >> m;
    m_dist.resize(n, vector<int>(m, INT_MAX));
    vis.resize(n, vector<bool>(m));
    lab.resize(n);
    pair<int, int> start;
    queue<tuple<int, int, int>> mq;
    for (int i = 0; i < n; i++) {
        cin >> lab[i];
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 'A') {
                start = {i, j};
            }
            else if (lab[i][j] == 'M') {
                mq.push({i, j, 0});
                m_dist[i][j] = 0;
            }
        }
    }

    while (!mq.empty()) {
        auto [row, col, dist] = mq.front();
        mq.pop();

        if (row > 0 && m_dist[row-1][col] == INT_MAX && lab[row-1][col] != '#') {
            m_dist[row-1][col] = dist+1;
            mq.push({row-1, col, dist+1});
        }
            
        if (col > 0 && m_dist[row][col-1] == INT_MAX && lab[row][col-1] != '#') {
            m_dist[row][col-1] = dist+1;
            mq.push({row, col-1, dist+1});
        }
            
        if (row < n-1 && m_dist[row+1][col] == INT_MAX && lab[row+1][col] != '#') {
            m_dist[row+1][col] = dist+1;
            mq.push({row+1, col, dist+1});
        }
            
        if (col < m-1 && m_dist[row][col+1] == INT_MAX && lab[row][col+1] != '#') {
            m_dist[row][col+1] = dist+1;
            mq.push({row, col+1, dist+1});
        }
            
    }

    queue<tuple<int, int, int>> qp;
    vector<vector<int>> p_dist(n, vector<int>(m, INT_MAX));
    qp.push({start.first, start.second, 0});
    p_dist[start.first][start.second] = 0;
    pair<int, int> backtrace;
    bool solved = false;
    while (!qp.empty()) {
        auto [row, col, dist] = qp.front();
        qp.pop();

        backtrace = {row, col};

        if (row == 0 || col == 0 || row == n-1 || col == m-1) {
            solved = true;
            break;
        }

        if (row > 0 && p_dist[row-1][col] == INT_MAX && lab[row-1][col] != '#' && dist+1 < m_dist[row-1][col]) {
            qp.push({row-1, col, dist+1});
            p_dist[row-1][col] = dist+1;
        }
            
        if (col > 0 && p_dist[row][col-1] == INT_MAX && lab[row][col-1] != '#' && dist+1 < m_dist[row][col-1]) {
            qp.push({row, col-1, dist+1});
            p_dist[row][col-1] = dist+1;
        }
            
        if (row < n-1 && p_dist[row+1][col] == INT_MAX && lab[row+1][col] != '#' && dist+1 < m_dist[row+1][col]) {
            qp.push({row+1, col, dist+1});
            p_dist[row+1][col] = dist+1;
        }
            
        if (col < m-1 && p_dist[row][col+1] == INT_MAX && lab[row][col+1] != '#' && dist+1 < m_dist[row][col+1]) {
            qp.push({row, col+1, dist+1});
            p_dist[row][col+1] = dist+1;
        }
            
    }

    if (!solved) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    stack<char> path;
    while (backtrace != start) {
        auto [row, col] = backtrace;
        map<int, tuple<int, int, int>> mp;
        if (row > 0) mp[p_dist[row-1][col]] = {row-1, col, 'D'};
        if (col > 0) mp[p_dist[row][col-1]] = {row, col-1, 'R'};
        if (row < n-1) mp[p_dist[row+1][col]] = {row+1, col, 'U'};
        if (col < m-1) mp[p_dist[row][col+1]] = {row, col+1, 'L'};

        backtrace = {get<0>((*mp.begin()).second), get<1>((*mp.begin()).second)};
        path.push(get<2>((*mp.begin()).second));
    }

    

    cout << path.size() << endl;
    while (!path.empty()) {
        cout << path.top();
        path.pop();
    }
}