#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1]-nums[0];

        auto check = [&](int m) -> bool {
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                if (abs(nums[i] - nums[i-1]) <= m) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= p;
        };
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (check(m))
                r = m;
            else
                l = m+1;
        }

        return l;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {8,9,1,5,4,3,6,4,3,7};
    sol.minimizeMax(vec, 4);
}