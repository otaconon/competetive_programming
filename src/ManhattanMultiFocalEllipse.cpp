#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
};

bool compareByX(const point& a, const point& b) {
    return a.x < b.x;
}

bool compareByY(const point& a, const point& b) {
    return a.y < b.y;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<point> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    vector<long long> dx(p.back().x - p.front().x);
    sort(p.begin(), p.end(), compareByX);

    for (int i = 0; i < n; i++) {
        dx[0] += abs(p.front().x - p[i].x);
    }

    int onLeft = 0, onRight = n;
    for (int x = p.front().x, i = 0; x <= p.back().x; x++) {
        int ind = x - p.front().x + 1;
        while (i < p.size() && x > p[i].x) {
            i++;
            onLeft++;
            onRight--;
        }
        dx[ind] = dx[ind - 1] + onRight - onLeft;
    }

    long long ans = 0;
    for (int i = 0; i < dx.size(); i++) {
        if (dx[i] <= d) {
            ans++;
        }
    }

    for (auto& d : dx) {
        cout << d << endl;
    }

    cout << ans << endl;
}