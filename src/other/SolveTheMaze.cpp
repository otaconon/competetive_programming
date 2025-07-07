#include <bits/stdc++.h>

using namespace std;

int t, n, m;
vector<string> maze;

bool G_next_to_B = false;
vector<vector<int>> visited;
int cnt_G = 0;

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || maze[r][c] == '#') {
        return;
    }

    if (maze[r][c] == 'G') {
        cnt_G++;
    }

    visited[r][c] = 1;

    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

bool check_cell(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m || maze[r][c] == 'B') {
        return false;
    }
    else if (maze[r][c] == 'G') {
        G_next_to_B = true;
        return false;
    }
    else {
        return true;
    }
}

int main() {
    cin >> t;
    while (t--) {
        bool end_t = false;

        cin >> n >> m;

        cnt_G = 0;
        G_next_to_B = false;
        maze.resize(n);
        visited = vector<vector<int>>(n, vector<int>(m));
        
        int x = 0;
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'G') {
                    x++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'B') {
                    if (check_cell(i - 1, j)) maze[i-1][j] = '#';
                    if (check_cell(i + 1, j)) maze[i+1][j] = '#';
                    if (check_cell(i, j - 1)) maze[i][j-1] = '#';
                    if (check_cell(i, j + 1)) maze[i][j+1] = '#';
                }
            }
        }

        if (G_next_to_B) {
            cout << "No" << '\n';
            continue;
        }

        floodfill(n-1, m-1);

        if (cnt_G == x) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }

        
    }
}