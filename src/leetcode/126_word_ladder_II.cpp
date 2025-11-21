#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string begin_word = "";
  vector<vector<string>> result;
  unordered_map<string, unordered_set<string>> parents;
  vector<string> *word_list;

  void backtrack(string node, vector<string> &path) {
    if (node == begin_word) {
      result.push_back(vector<string>(path.rbegin(), path.rend()));
      return;
    }

    for (string parent : parents[node]) {
      path.push_back(parent);
      backtrack(parent, path);
      path.pop_back();
    }
  }

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    word_list = &wordList;
    begin_word = beginWord;

    int n = wordList.size();

    unordered_set<string> word_set(wordList.begin(), wordList.end());
    unordered_set<string> level{beginWord};
    unordered_set<string> next_level;
    // parents.reserve(n);

    while (!level.empty()) {
      unordered_set<string> reached;
      for (string s : level) {
        string store_s = s;
        for (char &cur : s) {
          char store_cur = cur;
          for (char next = 'a'; next <= 'z'; next++) {
            cur = next;
            if (word_set.count(s)) {
              next_level.insert(s);
              parents[s].insert(store_s);
              reached.insert(s);
            }
          }
          cur = store_cur;
        }
      }

      for (string r : reached) {
        if (r == endWord) {
          vector<string> path{endWord};
          backtrack(endWord, path);
          return result;
        }
        word_set.erase(r);
      }
      level = std::move(next_level);
      next_level.clear();
    }

    return {};
  }
};

int main() {
  string beginWord = "hot";
  string endWord = "dog";
  vector<string> wordList = {"hot", "dog", "dot"};
  Solution sol;
  sol.findLadders(beginWord, endWord, wordList);
}