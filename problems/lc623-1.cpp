// 递归实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode dummy(-1);
        dummy.left = root;

        root = &dummy;

        helper(root, val, depth);

        return dummy.left;
    }

    // 递归
    void helper(TreeNode* root, int val, int depth) {
        --depth; // 层数减 1

        if (depth == 0) {
            auto temp1 = root->left;
            root->left = new TreeNode(val);
            root->left->left = temp1;

            auto temp2 = root->right;
            root->right = new TreeNode(val);
            root->right->right = temp2;
        } else {
            if (root->left) helper(root->left, val, depth);
            if (root->right) helper(root->right, val, depth);
        }
    }
};
