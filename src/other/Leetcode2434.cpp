#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        const int n = s.size();
        array<int, 26> cnt{};
        for (char c : s)
          cnt[c - 'a']++;

        string st;   st.reserve(n);
        string ans;  ans.reserve(n);
        int mn = 0;

        for (char c : s) {
            cnt[c - 'a']--;

            while (mn < 26 && cnt[mn] == 0)
              mn++;
            st.push_back(c);

            while (!st.empty() && (st.back() - 'a') <= mn) {
                ans.push_back(st.back());
                st.pop_back();
            }
        }

        ans.append(st.rbegin(), st.rend());
        return ans;
    }
};

int main() {

}