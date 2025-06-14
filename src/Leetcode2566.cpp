#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string remap(string s, char a, char b) {
        for (int j = 0; j < s.size(); j++)
            s[j] = s[j] == a ? b : s[j];
        return s;
    }
    int minMaxDifference(int num) {
        string s = to_string(num);
        int mx = 0;
        int mn = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            string t = remap(s, s[i], '9');
            mx = max(mx, stoi(t));
            t = remap(s, s[i], '0');
            mn = min(mn, stoi(t));
        }
        return mx - mn; 
    }
};

int main() {
    Solution sol;
    sol.minMaxDifference(11891);
}