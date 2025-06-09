#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        N = n;
        vector<int> ans;
        for (int i = 1; i <= 9; i++)
            dfs(i, ans);

        return ans;
    }

    void dfs(int x, vector<int>& ans) {
        if (x > N)
            return;

        ans.push_back(x);

        for (int i = 0; i <= 9; i++) {
            int next = x * 10 + i;
            dfs(next, ans);
        }
    }

private:
    int N;
};

int main() {

}