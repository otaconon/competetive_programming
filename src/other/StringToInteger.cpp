#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            return 0;
        
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        while (i < n && s[i] == '0')
            i++;
        if (i == n)
            return 0;
        
        int j = i;
        while (j < n && isdigit(s[j]))
            j++;

        string k = s.substr(i, min(11, j-i));
        if (k == "")
            return 0;

        auto temp = stol(k) * sign;
        if (temp < 0)
            temp = max((long)INT_MIN, temp);
        else
            temp = min((long)INT_MAX, temp);
        
        return temp;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("21474836460") << '\n';
}