#include <unordered_set>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << ' ';
  cout << '\n';
}

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
      int n = status.size();
      found_boxes.resize(n);
      found_keys.resize(n);
      vis.resize(n);

      for (auto u : initialBoxes)
        found_boxes[u] = true;

      for (int i = 0; i < n; i++)
        if (status[i])
          found_keys[i] = true;

      for (int i = 0; i < n; i++)
        if (found_boxes[i] && found_keys[i])
          boxes_q.push(i);

      while (!boxes_q.empty()) {
        int u = boxes_q.front();
        boxes_q.pop();
        if (vis[u])
          continue;

        vis[u] = true;
        candies_cnt += candies[u];
        
        for (auto b : containedBoxes[u]) {
          if (found_keys[b])
            boxes_q.push(b);
          else
            found_boxes[b] = true;
        }
        for (auto k : keys[u]) {
          if (found_boxes[k])
            boxes_q.push(k);
          else
            found_keys[k] = true;
        }

      }

      return candies_cnt;
    }

private:
  vector<bool> vis;
  vector<bool> found_boxes;
  vector<bool> found_keys;
  queue<int> boxes_q;
  long long candies_cnt = 0;
};

int main() {
  Solution sol;
  vector<int> status = {1, 0, 1, 0};
  vector<int> candies = {7, 5, 4, 100};
  vector<vector<int>> keys = {{}, {}, {1}, {}};
  vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
  vector<int> initialBoxes = {0};
  sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
}