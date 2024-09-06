#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;
map<pair<int, int>, vector<pair<int, int>>> switches;

vector<pair<int, int>> lightQ;
vector<pair<int, int>> darkQ;
vector<vector<bool>> lightsOn;
vector<vector<bool>> vis;

void floodfill(int r, int c) {
    if (r <= 0 || r > n || c < 0 || c > n || vis[r][c]) {
        return;
    }

    if (lightsOn[r][c]) {
        vis[r][c] = true;
        lightQ.push_back({r, c});
    }
    else darkQ.push_back({r, c});
}

int main() {
    setIO("lightson");

    cin >> n >> m;

    lightsOn.resize(n + 1, vector<bool>(n + 1));
    vis.resize(n+1, vector<bool>(n+1));

    for (int i = 0; i < m; i++) {
        int c, r, a, b;
        cin >> c >> r >> a >> b;

        switches[{r, c}].push_back({b, a});
    }

    lightQ.push_back({1, 1});
    lightsOn[1][1] = true;

    while (!lightQ.empty()) {
        while (!lightQ.empty()) {
            int r = lightQ.back().first, c = lightQ.back().second;
            lightQ.pop_back();

            for (auto& sw: switches[{r, c}]) {
                lightsOn[sw.first][sw.second] = true;
            }

            floodfill(r-1, c);
            floodfill(r+1, c);
            floodfill(r, c-1);
            floodfill(r, c+1);
        }

        vector<pair<int, int>> prev_darkQ = darkQ;
        darkQ = vector<pair<int, int>>();

        while (!prev_darkQ.empty()) {
            int r = prev_darkQ.back().first, c = prev_darkQ.back().second;
            prev_darkQ.pop_back();

            floodfill(r, c);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (lightsOn[i][j]) ans++;
        }
    }

    cout << ans << '\n';
}