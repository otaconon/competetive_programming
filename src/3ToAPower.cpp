#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;

    std::vector<int> ans;
    int i = 0;
    while (m >= 1) {
        if (m % 3 == 2) {
            ans.push_back(i);
            ans.push_back(i);
        }
        else if (m % 3 == 1){
            ans.push_back(i);
        }

        i++;
        m /= 3;
    }

    cout << ans.size() << endl;
    for (auto& num : ans) {
        cout << num << ' ';
    }
}