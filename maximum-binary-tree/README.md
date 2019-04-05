# 最大值二叉树
给定一个不重复的整数数组，构造二叉树，要求如下：
1. 跟节点是数组中的最大值；
2. 左子树是左子数组的最大值；
3. 右子树是右子数组的最大值；
[maxinum-binary-tree](https://leetcode.com/problems/maximum-binary-tree/)

## 递归解法
- 复杂度 平均：`O(nlog(n))`；最差：`O(n*n)`
```cpp
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
```

## 栈解法

使用一个 `vector` 来模拟栈的行为，其中保存的是当前节点的父节点；`parents[0]` 表示根节点；数组尾部表示栈顶；

从前往后遍历 `numbers` 数组，有以下两种情形：
- 这个数比栈顶小：将这个数入栈；
- 这个数比栈顶大：将栈中的元素弹出，知道满足：当前栈顶的数比这个数大；
  - 如果出栈的过程中没有满足条件的祖先节点，这个数既是根节点；
  - 如果发现该节点，将此节点插入到树中；

```cpp
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
```