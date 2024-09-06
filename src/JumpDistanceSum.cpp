#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Point {
    int x, y;

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

void brute() {
    int n;
    cin >> n;
    vector<Point> p(n);

    long long diag1 = 0;
    long long diag2 = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    set<Point> used;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || used.find(p[j]) != used.end())
                continue;
            
            if ((p[i].x + p[i].y) % 2 != (p[j].x + p[j].y) % 2)
                continue;
            
            ans += max(abs(p[i].x - p[j].x), abs(p[i].y - p[j].y));
        }
        used.insert(p[i]);
    }

    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<Point>> p(2);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        if ((x + y) % 2 == 0) {
            p[0].push_back({x + y, x - y});
        }
        else {
            p[1].push_back({x + y, x - y});
        }
    }

    ll ans = 0;
    for (auto& a : p) {
        vector<int> vx, vy;
        for (auto& [x, y] : a) {
            vx.push_back(x);
            vy.push_back(y);
        }

        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());

        for (int i = 1; i < (int)vx.size(); i++) {
            ans += i * (ll)(vx.size() - i) * (ll)(vx[i] - vx[i-1]);
        }
        for (int i = 1; i < (int)vy.size(); i++) {
            ans += i * (ll)(vy.size() - i) * (ll)(vy[i] - vy[i-1]);
        }
    }

    cout << ans / 2 << endl;
}

int main() {
    solve();
}