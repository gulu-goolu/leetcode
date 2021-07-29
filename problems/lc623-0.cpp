// 在二叉树中增加一行
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
        TreeNode dummy(0);
        dummy.left = root;

        root = &dummy;
        // 找到所有深度为 depth - 1 的节点，然后用 val 构造的新节点替换，替换时要注意顺序
        std::vector<TreeNode*> depth_1_nodes = [root, &depth]() {
            std::vector<TreeNode*> cur, next; // 层序遍历当前层，下一层
            cur.push_back(root);

            while (--depth) {
                for (auto t: cur) {
                    if (t->left) next.push_back(t->left);
                    if (t->right) next.push_back(t->right);
                }

                const auto debug = [&]() {
                    std::stringstream ss;
                    for (auto it = next.begin(); it != next.end(); ++it) {
                        ss << (*it)->val << ",";
                    }
                    printf("depth: %d, next: %s\n", depth, ss.str().c_str());
                };
                // debug();

                cur = std::move(next);
            }

            return cur;
        } ();

        for (auto n: depth_1_nodes) {
            auto temp1 = n->left;
            n->left = new TreeNode(val);
            n->left->left = temp1;

            auto temp2 = n->right;
            n->right = new TreeNode(val);
            n->right->right = temp2;
        }

        return dummy.left;
    }
};
