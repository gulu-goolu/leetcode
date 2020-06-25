struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *recursive(int *nums, int count) {
    if (count == 0)
        return nullptr;
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

#include <vector>

TreeNode *construct_maximum_binary_tree2(const std::vector<int> &numbers) {
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

int main(int argc, char *argv[]) {
    int arr[] = { 3, 2, 1, 6, 0, 5 };
    construct_maximum_binary_tree(arr, 6);
    TreeNode *tree = construct_maximum_binary_tree2({ 3, 2, 1, 6, 0, 5 });
}
