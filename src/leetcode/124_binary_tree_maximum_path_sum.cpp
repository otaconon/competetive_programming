#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int ans = -1e9;

  int search(TreeNode *node) {
    if (node == nullptr)
      return 0;
    
    int sum_left = search(node->left);
    int sum_right = search(node->right);
    int path_sum = sum_left + sum_right + node->val;
    int best_partial = max(node->val, max(sum_left + node->val, sum_right + node->val));
    int best_final = max(path_sum, best_partial);
    ans = max(ans, best_final);
    return best_partial;
  }

  int maxPathSum(TreeNode *root) {
    search(root);
    return ans;
  }
};