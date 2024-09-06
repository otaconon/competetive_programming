#include <bits/stdc++.h>

using namespace std;

struct Train {
    int a, b, s, t;

    bool operator<(const Train& other) {
        return t < other.t;
    }
};

int main() {
    int n, m, x1;
    cin >> n >> m >> x1;
    vector<Train> trains(m);

    for (int i = 0; i < m; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        a--; b--;
        trains.emplace_back(a, b, s, t);
    }

    sort(trains.begin(), trains.end());

    vector<int> city_delay(n);
    for (auto& train : trains) {
        
    }
}