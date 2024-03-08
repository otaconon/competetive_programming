#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;
vector<vector<int>> course;
vector<vector<int>> waypoints;

vector<vector<int>> value_map;
vector<vector<bool>> visited;

int finish_cnt = 0;

void floodfill(int r, int c, int d) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c]) {
        return;
    }

    visited[r][c] = true;

    if (waypoints[r][c]) {
        finish_cnt++;
    }

    if (r > 0) {
        if (abs(course[r][c] - course[r-1][c]) <= d) floodfill(r - 1, c, d);
    }
    if (r < n-1) {
        if (abs(course[r][c] - course[r+1][c]) <= d) floodfill(r + 1, c, d);
    }
    if (c > 0) {
        if (abs(course[r][c] - course[r][c-1]) <= d) floodfill(r, c - 1, d);
    }
    if (c < m-1) {
        if (abs(course[r][c] - course[r][c+1]) <= d) floodfill(r, c + 1, d);
    }
}

int main() {
    setIO("ccski");

    cin >> n >> m;
    course.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    value_map.resize(n, vector<int>(m));
    waypoints.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> course[i][j];
        }
    }

    pair<int, int> arb_waypoint = {-1, -1};
    int req_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> waypoints[i][j];
            if(waypoints[i][j] == 1) {
                arb_waypoint = {i, j};
                req_cnt++;
            }
        }
    }

    int lo = 0, hi = 1000000005;
    int minD = -1;
    while (lo <= hi) {
        finish_cnt = 0;
        visited = vector<vector<bool>>(n, vector<bool>(m));

        int mid = (lo + hi) / 2;

        floodfill(arb_waypoint.first, arb_waypoint.second, mid);

        if (finish_cnt == req_cnt) {
            minD = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    cout << minD << '\n';
}
