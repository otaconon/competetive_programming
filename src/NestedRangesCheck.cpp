#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> a;
map<pair<int, int>, int> id;
vector<bool> contains;
vector<bool> contained;

template<typename T>
void printVec(vector<T>& vec) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void solve() {
    sort(a.begin(), a.end(), [](auto& left, auto& right) {
        if (left.first == right.first) {
            return left.second > right.second;
        }
        return left.first < right.first;
    });

    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second <= maxEnd) {
            contained[id[a[i]]] = true;
        }
        maxEnd = max(maxEnd, a[i].second);
    }

    int minEnd = 1e9+1;
    for (int i = n-1; i >= 0; i--) {
        if (a[i].second >= minEnd) {
            contains[id[a[i]]] = true;
        }
        minEnd = min(minEnd, a[i].second);
    }

    printVec(contains);
    printVec(contained);
}

int main() {
    cin >> n;
    a.resize(n);
    contained.resize(n);
    contains.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        id[a[i]] = i;
    }

    solve();
}