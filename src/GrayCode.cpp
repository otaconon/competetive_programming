#include <bits/stdc++.h>

using namespace std;

vector<string> grayCode(int n) {
    vector<string> res;

    if (n == 1) {
        res.push_back("0");
        res.push_back("1");
        return res;
    }

    vector<string> curr = grayCode(n-1);

    for (int i = 0; i < curr.size(); i++) {
        res.push_back("0" + curr[i]);
    }

    for (int i = curr.size() - 1; i >= 0; i--) {
        res.push_back("1" + curr[i]);
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = grayCode(n);

    for (auto& x: ans) {
        cout << x << endl;
    }
}