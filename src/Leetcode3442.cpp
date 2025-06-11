#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        array<int, 26> cnt{};
        for (auto c : s)
            cnt[c - 'a']++;
        
        int a1 = -1, a2 = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1)
                a1 = max(a1, cnt[i]);
            else
                a2 = min(a2, cnt[i] == 0 ? INT_MAX : cnt[i]);
        }

        return a1 - a2;
    }
};

int main() {
    Solution sol;
    cout << sol.maxDifference("aaaaabbc") << '\n';
}