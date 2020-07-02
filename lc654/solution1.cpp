struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *recursive(int *nums, int count) {
  if (count == 0) return nullptr;
  int index = 0;
  int max = nums[index];
  for (int i = 0; i < count; ++i) {
    if (nums[i] > max) {
      max = nums[i];
      index = i;
    }
  }
  TreeNode *node = new TreeNode(nums[index]);
  node->left = recursive(nums, index);
  node->right = recursive(nums + index + 1, count - index - 1);
  return node;
}

TreeNode *construct_maximum_binary_tree(int *numbers, int count) {
  return recursive(numbers, count);
}

int main() {}