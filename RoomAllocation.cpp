#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, set<int>> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        m[a[i]].insert(i+1);
        m[b[i]+1].insert(-(i+1));
    }

    priority_queue<int, vector<int>, greater<int>> available;
    for (int i = 1; i <= n; i++) {
        available.push(i);
    }

    int maxCustomers = 0;
    int cntCustomers = 0;
    map<int, int> used;
    for (auto& [key, value]: m) {
        for (auto& x : value) {
            if (x > 0) {
                cntCustomers++;

                used[x] = available.top();
                available.pop();
            }
            else {
                cntCustomers--;
                available.push(used[-x]);
            }
        }
        maxCustomers = max(maxCustomers, cntCustomers);
    }

    cout << maxCustomers << '\n';

    for (auto& [key, value]: used) {
        cout << value << ' ';
    }
}