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
        // 用一个栈辅助遍历
        std::stack<TreeNode*> todo;
        std::vector<int> res;
        TreeNode * cur = root;
        while (cur || !todo.empty()) {
            while (cur) {
                todo.push(cur);
                cur = cur->left;
            }

            cur = todo.top(); todo.pop();
            res.push_back(cur->val);

            const auto debug = [&]() {
                auto temp = todo;
                std::stringstream ss;
                while (!temp.empty()) {
                    ss << temp.top()->val << ", ";
                    temp.pop();
                }
                printf("process: %d, todo: %s\n", cur->val, ss.str().c_str());
            };
            // debug();

            if (cur->right) {
                cur = cur->right;
            } else {
                cur = nullptr;
            }
        }
        return res;
    }
};
