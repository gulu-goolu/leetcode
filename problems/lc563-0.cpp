// 递归
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
    int findTilt(TreeNode* root) {
        return helper(root).first;
    }

    // <tilt, sum>
    std::pair<int, int> helper(TreeNode* node) {
        if (!node) {
            return std::pair<int, int>(0, 0);
        }

        auto left = helper(node->left);
        auto right = helper(node->right);

        int tilt = left.first + right.first + std::abs<int>(left.second - right.second);
        int sum = node->val + left.second + right.second;
        auto res = std::pair<int, int>(tilt, sum);
        // printf("node: %d, res: <%d, %d>\n", node->val, res.first, res.second);
        return res;
    }
};
