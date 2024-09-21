#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<pair<long long, int>> x(n);
    vector<long long> left_positions, right_positions;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < n; i++) {
        if (s[x[i].second] == '0') {
            left_positions.push_back(x[i].first);
        } else {
            right_positions.push_back(x[i].first);
        }
    }

    long long ans = 0;
    int j = 0;
    for (int i = 0; i < right_positions.size(); i++) {
        long long x_i = right_positions[i];
        long long x_max = x_i + 2 * t;

        int count = upper_bound(left_positions.begin(), left_positions.end(), x_max) -
                    lower_bound(left_positions.begin(), left_positions.end(), x_i);

        ans += count;
    }

    cout << ans << endl;
    return 0;
}