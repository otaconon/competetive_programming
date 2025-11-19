#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int begin_idx = -1, end_idx = -2;
  int shortest_path = 1;
  vector<vector<string>> result;
  vector<set<int>> parents;
  vector<string> *word_list;

  void backtrack(int node, vector<string>& path) {
    if (path.size() > shortest_path)
      return;

    if (node == begin_idx) {
      result.push_back(vector<string>(path.rbegin(), path.rend()));
      return;
    }

    for (int parent : parents[node]) {
      path.push_back((*word_list)[parent]);
      backtrack(parent, path);
      path.pop_back();
    }
  }

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    word_list = &wordList;

    for (int i = 0; i < wordList.size(); i++) {
      if (wordList[i] == beginWord)
        begin_idx = i;
      if (wordList[i] == endWord)
        end_idx = i;
    }
    if (begin_idx == -1) {
      wordList.insert(wordList.begin(), beginWord);
      begin_idx = 0;
      end_idx++;
    }
    if (end_idx == -1)
      return {};

    int n = wordList.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < beginWord.size(); k++)
          if (wordList[i][k] != wordList[j][k])
            cnt++;
        if (cnt == 1) {
          g[i].push_back(j);
        }
      }
    }

    parents.resize(n);
    vector<bool> vis(n);
    queue<int> q;
    queue<int> update;
    bool reached = false;
    update.push(begin_idx);
    while (!update.empty() && !reached) {
      shortest_path++;

      while (!update.empty()) {
        auto u = update.front();
        update.pop();
        if (vis[u])
          continue;
        q.push(u);
      }

      while (!q.empty()) {
        auto u = q.front();
        vis[u] = true;
        q.pop();

        for (auto v : g[u]) {
          update.push(v);
          parents[v].insert(u);
          if (v == end_idx)
            reached = true;
        }
      }
    }

    if (!reached)
      return {};

    vector<string> path{endWord};
    backtrack(end_idx, path);

    return result;
  }
};

int main() {
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
  Solution sol;
  sol.findLadders(beginWord, endWord, wordList);
}