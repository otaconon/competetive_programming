#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int res = 1;

    unordered_set<string> word_set(wordList.begin(), wordList.end());
    if (word_set.find(endWord) == word_set.end())
      return 0;

    unordered_set<string> begin_set{beginWord};
    unordered_set<string> end_set{endWord};
    unordered_set<string> next_set;
    word_set.erase(beginWord);
    word_set.erase(endWord);

    while (!begin_set.empty() && !end_set.empty()) {
      res++;

      if (begin_set.size() > end_set.size())
        swap(begin_set, end_set);

      for (auto s : begin_set) {
        for (char &cur : s) {
          char store_cur = cur;
          for (char next = 'a'; next <= 'z'; next++) {
            cur = next;

            if (end_set.count(s))
              return res;

            if (word_set.count(s)) {
              next_set.insert(s);
              word_set.erase(s);
            }
          }
          cur = store_cur;
        }
      }

      begin_set = std::move(next_set);
      next_set.clear();
    }

    return 0;
  }
};

int main() {
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
  Solution sol;
  sol.ladderLength(beginWord, endWord, wordList);
}