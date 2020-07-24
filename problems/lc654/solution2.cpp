//
// Created by chj on 2020/7/2.
//
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *construct_maximum_binary_tree(const std::vector<int> &numbers) {
  std::vector<TreeNode *> parents;
  parents.push_back(new TreeNode(numbers[0]));
  for (int i = 1; i < numbers.size(); ++i) {
    TreeNode *node = new TreeNode(numbers[i]);
    if (node->val < parents.back()->val) {
      parents.back()->right = node;
    } else {
      TreeNode *parent = parents.back();
      TreeNode *child = nullptr;
      while (parent->val < node->val) {
        child = parent;
        parents.pop_back();
        if (parents.empty()) {
          parent = nullptr;
          break;
        }
        parent = parents.back();
      }
      node->left = child;
      if (parent) {
        parent->right = node;
      }
    }
    parents.push_back(node);
  }
  return parents[0];
}

int main() {}
