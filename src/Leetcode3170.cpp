#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int get_smallest(vector<vector<int>>& vec) {
      for (int i = 0; i <= 26; i++)
        if (vec[i].size() > 0)
          return vec[i].back();
      return -1;
    }

    string clearStars(string s) {
      vector<vector<int>> cnt(27);
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
          int idx = get_smallest(cnt);
          cnt[s[idx] - 'a'].pop_back();
          s[idx] = ' ';
        }
        else {
          cnt[s[i] - 'a'].push_back(i);
        }
      }

      string ans = "";
      for (auto c : s)
        if (c != ' ' && c != '*')
          ans += c;
      
      return ans;
    }
};

int main() {

}