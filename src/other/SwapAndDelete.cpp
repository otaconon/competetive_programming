#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        priority_queue<int> zeros, ones;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                zeros.push(-i);
            else if (s[i] == '1')
                ones.push(-i);
        }

        while (!zeros.empty() && !ones.empty()) {
            swap(s[-zeros.top()], s[-ones.top()]);
            zeros.pop();
            ones.pop();
        }

        int cnt = 0;
        if (zeros.empty() && ones.empty()) {
            cout << 0 << endl;
            continue;
        }
        else
            cnt = zeros.empty() ? ones.top() : zeros.top();
        std::cout << s.size() + cnt << endl;
    }
}