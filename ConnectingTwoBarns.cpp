#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t;
int n, m;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;

        vector<vector<int>> net(n);
        vector<int> visited(n, -1);
        int currComponent = 0;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            net[a].push_back(b);
            net[b].push_back(a);
        }


        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                vector<int> s;
                s.push_back(i);
                while (!s.empty()) {
                    int node = s.back();
                    s.pop_back();
                    if (visited[node] != -1) continue;

                    visited[node] = currComponent;

                    for (auto adj: net[node]) {
                        s.push_back(adj);
                    }
                }
                currComponent++;
            }
        }


        vector<vector<int>> components(currComponent);

        for (int i = 0; i < n; i++) {
            components[visited[i]].push_back(i);
        }

        vector<int> barn1 = components[visited[0]];
        vector<int> barn2 = components[visited[n-1]];

        vector<long long> dist1(currComponent, INT_MAX);
        vector<long long> dist2(currComponent, INT_MAX);

        int barn1Id = 0;
        for (int i = 0; i < n; i++) {
            long long dist = abs(barn1[barn1Id] - i);

            while (barn1Id < barn1.size()-1 && abs(barn1[barn1Id+1] - i) < dist) barn1Id++;

            dist1[visited[i]] = min(dist, dist1[visited[i]]);
        }

        int barn2Id = 0;
        for (int i = 0; i < n; i++) {
            long long dist = abs(barn2[barn2Id] - i);

            while (barn2Id < barn2.size()-1 && abs(barn2[barn2Id+1] - i) < dist) barn2Id++;

            dist2[visited[i]] = min(dist, dist2[visited[i]]);
        }

        long long minimum = LLONG_MAX;
        for (int i = 0; i < currComponent; i++) {
            long long cost = dist1[i] * dist1[i] + dist2[i] * dist2[i];
            minimum = min(minimum, cost);
        }

        cout << minimum << '\n';
    }
}