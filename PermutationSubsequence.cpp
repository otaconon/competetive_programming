#include <bits/stdc++.h>

using namespace std;

struct CompareBySecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }

    set<pair<int, int>, CompareBySecond> a;
    for (int i = 1; i <= k; i++) {
        a.emplace(i, p[i]);
    }

    int ans = (*a.rbegin()).second - (*a.begin()).second;
    for (int i = k+1; i <= n; i++) {
        a.erase(make_pair(i-k, p[i-k]));
        a.emplace(i, p[i]);
        ans = min(ans, (*a.rbegin()).second - (*a.begin()).second);
    }

    cout << ans << endl;
}