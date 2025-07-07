#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n;
vector<string> grid;
vector<vector<int>> visited;

int current_area = 0;
int max_area = 0;

int max_perimeter = 0;
int current_perimeter = 0;

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == '.') {
        current_perimeter++;
        return;
    }
    else if (visited[r][c]) {
        return;
    }
    
    current_area++;
    visited[r][c] = true;

    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main() {
    setIO("perimeter");

    cin >> n;
    grid.resize(n);
    visited.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            current_area = 0;
            current_perimeter = 0;

            if (grid[i][j] == '#' && !visited[i][j]) {
                floodfill(i, j);
            }

            if (current_area > max_area) {
                max_area = current_area;
                max_perimeter = current_perimeter;
            }
            else if (current_area == max_area) {
                max_perimeter = min(max_perimeter, current_perimeter);
            }
            
        }
    }

    cout << max_area << ' ' << max_perimeter << endl;
}