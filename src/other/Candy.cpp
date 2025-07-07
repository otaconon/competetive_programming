//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i-1])
                ans[i] = ans[i-1]+1;
        
        for (int i = n-2; i >= 0; i--)
            if (ratings[i] > ratings[i+1])
                ans[i] = max(ans[i], ans[i+1]+1);
        
        
        return accumulate(ans.begin(), ans.end(), 0);
    }
};


int main() {
    Solution sol;
    vector<int> ratings{1, 0, 2};
    cout << sol.candy(ratings) << '\n';
}