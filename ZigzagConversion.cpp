#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) 
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        return std::ranges::fold_left(rows, std::string{}, std::plus<>());
    }
};

int main() {
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 4) << endl;
    cout << sol.convert("AB", 2) << endl;
}