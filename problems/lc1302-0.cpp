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
    int deepestLeavesSum(TreeNode* root) {
        // 层序遍历，找到最深的一层，然后求和
        std::vector<TreeNode*> todo;
        std::vector<TreeNode*> nodes;

        // init
        todo.push_back(root);

        while (!todo.empty()) {
            std::vector<TreeNode*> next;
            for (auto t: todo) {
                if (t->left) next.push_back(t->left);
                if (t->right) next.push_back(t->right);
            }

            nodes = std::move(todo);
            todo = std::move(next);

            const auto debug = [&]() {
                std::stringstream ss;
                for (auto it = nodes.begin(); it != nodes.end(); ++it) {
                    ss << (*it)->val << ", ";
                }
                printf("nodes: %s\n", ss.str().c_str());
            };
            // debug();
        }

        int res = 0;
        for (auto t: nodes) res += t->val;

        return res;
    }
};
