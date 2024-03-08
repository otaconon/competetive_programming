#include <bits/stdc++.h>

using namespace std;

void solveNLogN() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    
    sort(a.begin(), a.end());

    vector<int> ans(n+1);
    set<int> values;

    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s.top().first != a[i].first) {
            while (!s.empty()) {
                values.insert(s.top().second);
                s.pop();
            }
        }

        s.push(a[i]);
        auto it = values.lower_bound(a[i].second);

        int nearest = -1;
        if (it == values.begin()) {
            nearest = 0;
        }
        else {
            it--;
            nearest = *it;
        }

        ans[a[i].second] = nearest;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}

void solveN() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> ans(n);
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first >= a[i]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = 0;
        }
        else {
            ans[i] = s.top().second+1;
        }

        s.push(make_pair(a[i], i));
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}

int main() {
    solveN();
}