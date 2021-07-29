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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        helper(res, root);
        return res;
    }

    void helper(std::vector<int>& v, TreeNode* node) {
        if (!node) {
            return;
        }

        helper(v, node->left);
        v.push_back(node->val);
        helper(v, node->right);
    }
};
