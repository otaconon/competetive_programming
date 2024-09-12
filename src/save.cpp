vector<long long> dy(2 * 1e3);
    sort(p.begin(), p.end(), compareByY);
    for (int i = 0; i < 1e3; i++) {
        dy[0] += abs(p[0].y - p[i].y);
    }
    for (int i = 1; i < n; i++) {
        dy[i] = dy[i-1] - (n - i) * p[i-1].y + abs(p[i-1].y - p[i].y);
    }