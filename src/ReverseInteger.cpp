#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        auto s = to_string(x);
        int n = s.size();
        std::reverse(s.begin(), s.end());
        string mx = "";
        bool possible_overflow = false;
        if (x >= 0) {
            mx = to_string(INT_MAX);
            if (s.size() == mx.size())
                possible_overflow = true;
        }
        else {
            mx = to_string(INT_MIN);
            s = s[n-1] + s.substr(0, n-1);
            if (s.size() == mx.size())
                possible_overflow = true;
        }
        
        //cout << s << endl;
        if (!possible_overflow)
            return stoi(s);

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (s[i] < mx[i]) {
                ok = true;
                break;
            }
            else if (s[i] > mx[i]) {
                break;
            }
        }
        if (mx != s && !ok)
            return 0;

        return stoi(s);
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(2147483647) << endl;
}