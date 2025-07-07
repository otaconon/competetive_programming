#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = -INT_MAX;
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                if (a == b)
                    continue;

                int prevA = 0, prevB = 0;
                int cntA = 0, cntB = 0;
                vector<int> best(4, INT_MAX);
                for (int l = -1, r = 0; r < s.size(); r++) {
                    cntA += (s[r] - '0' == a);
                    cntB += (s[r] - '0' == b);
                    
                    while (r - l >= k && cntB - prevB >= 2) {
                        int state = ((prevA & 1) << 1) | (prevB & 1);
                        best[state] = min(best[state], prevA - prevB);
                        l++;
                        prevA += (s[l] - '0' == a);
                        prevB += (s[l] - '0' == b);
                    }

                    int state = ((cntA & 1) << 1) | (cntB & 1);
                    int need_state = state ^ 0b10;
                    if (best[need_state] != INT_MAX)
                        ans = max(ans, (cntA - cntB) - best[need_state]);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    sol.maxDifference("12233", 4);
}