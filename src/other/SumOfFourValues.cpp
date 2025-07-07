#include <bits/stdc++.h>

using namespace std;

void my_sol() {
    int n, x;
    cin >> n >> x;
    vector<pair<long long, long long>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    vector<vector<long long>> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                vector<long long> c = {a[i].first + a[j].first, a[i].second, a[j].second};
                b.push_back(c);
            }
        }
    }

    sort(b.begin(), b.end());
    
    vector<long long> foundAt = {-1, -1, -1, -1};

    for (int i = 0; i < b.size(); i++) {
        vector<long long> val = {x - b[i][0], 0, 0, 0};
        auto it = lower_bound(b.begin(), b.end(), val,
                               [](const std::vector<long long>& a, const std::vector<long long>& b) {
                                   return a[0] < b[0];
                               });

        while (it != b.end() && it->at(0) + b[i][0] == x) {

            if (it->at(1) == b[i][1] || it->at(1) == b[i][2] || it->at(2) == b[i][1] || it->at(2) == b[i][2]) {
                it++;
            }
            else {
                foundAt = {it->at(1), it->at(2), b[i][1], b[i][2]};
                break;
            }
        }

        if (foundAt[0] != -1)
            break;
    }

    sort(foundAt.begin(), foundAt.end());

    if (foundAt[0] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    for (int i = 0; i < 4; i++) {
        cout << foundAt[i] << ' ';
    }
    cout << '\n';
}

void better_sol() {
    int n, x;
    cin >> n >> x;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];

    unordered_map<int, pair<int, int>> valuesToPosition;
    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if (valuesToPosition.count(x - values[i] - values[j])) {
                cout << i+1 << ' ' << j+1 << ' '
                    << valuesToPosition[x - values[i] - values[j]].first + 1 << ' '
                    << valuesToPosition[x - values[i] - values[j]].second + 1;
                return;
            }
        }

        for (int j = 0; j < i; j++) {
            valuesToPosition[values[i] + values[j]] = {i, j};
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    better_sol();
}