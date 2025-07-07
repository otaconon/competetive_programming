#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
    int x, y;
    int id;

    bool operator<(const Range& other) const {
        if (x == other.x) {
        return y > other.y;
    }
    return x < other.x;
    }
};

int n;
vector<Range> rangesArr;
vector<int> contained;
vector<int> contains;

template<typename T>
void printVec(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    sort(rangesArr.begin(), rangesArr.end());

    ordered_set<pair<int, int>> maxEnds;
    for (int i = 0; i < n; i++) {
        contained[rangesArr[i].id] = maxEnds.size() - maxEnds.order_of_key({rangesArr[i].y, -i});
        maxEnds.insert({rangesArr[i].y, -i});
    }

    ordered_set<pair<int, int>> minEnds;
    for (int i = n-1; i >= 0; i--) {
        contains[rangesArr[i].id] = minEnds.order_of_key({rangesArr[i].y, rangesArr[i].id});
        minEnds.insert({rangesArr[i].y, -rangesArr[i].id});
    }

    printVec(contains);
    printVec(contained);

}

int main() {
    cin >> n;
    rangesArr.resize(n);
    contained.resize(n);
    contains.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> rangesArr[i].x >> rangesArr[i].y;
        rangesArr[i].id = i;
    }

    solve();
}