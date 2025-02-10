#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void brute() {
    int n;
    cin >> n;
    vector<vector<int>> cows(n);
    for (int i = 0; i < n*2; i++) {
        int x;
        cin >> x;
        cows[--x].push_back(i);
    }

    int ans = 0;
    int m = 2*n;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int dist = cows[i][1] - cows[i][0];
            int d1 = (cows[j][0] - cows[i][0] + m) % m;
            int d2 = (cows[j][1] - cows[i][0] + m) % m;
            if ((d1 < dist && d2 > dist) || (d1 > dist && d2 < dist)) {
                ans++;
            }
       }
    }

    cout << ans << endl;
}

void solve() {
    int n;
    cin >> n;
    int m = 2*n;
    Tree<pair<int, int>> points;
    vector<int> track(m);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        if (points.find({track[x], x}) == points.end()) {
            track[x] = i;
            points.insert({i, x});
        }
        else {
            ans += points.size() - points.order_of_key({track[x], x}) - 1;
            points.erase({track[x], x});
        }
    }

    cout << ans << endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (argv[1] == "brute")
            brute();
        else
            solve();
    }
    else {
        setIO("circlecross");
        solve();
    }
}