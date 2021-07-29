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
    int tilt = 0;
    int findTilt(TreeNode* root) {
        helper(root);
        return tilt;
    }

    // return sum of this node
    int helper(TreeNode* node) {
        if (!node) return 0;

        int left = helper(node->left);
        int right = helper(node->right);
        tilt += std::abs<int>(left - right);

        return node->val + left + right;
    } 
};
