/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    using Graph = std::unordered_map<TreeNode*, std::vector<TreeNode*>>; // <node, neighbors>
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) {
            return {};
        }

        Graph g;
        build_graph(g, root, nullptr);
        
        const auto debug = [&g]() {
            for (const auto& item: g) {
                std::stringstream ss;
                for (auto it = item.second.begin(); it != item.second.end();) {
                    ss << (*it)->val;
                    if (++it != item.second.end()) {
                        ss << ",";
                    }
                }
                printf("%d: %s\n", item.first->val, ss.str().c_str());
            }
        };
        // debug();

        // 宽度优先搜索
        std::vector<TreeNode*> cur, next;
        std::unordered_set<TreeNode*> visited;
        
        cur.push_back(target);
        visited.insert(target);

        while (k--) {
            for (auto& n: cur) {
                for (auto& neighbor: g[n]) {
                    if (visited.find(neighbor) != visited.end()) continue;

                    next.push_back(neighbor);
                    visited.insert(neighbor);
                }
            }

            const auto debug = [&next]() {
                std::stringstream ss;
                for (auto it = next.begin(); it != next.end();) {
                    ss << (*it)->val;
                    if (++it != next.end()) {
                        ss << ",";
                    }
                }
                printf("next: %s\n", ss.str().c_str());
            };
            // debug();

            cur = std::move(next);
        }

        std::vector<int> res;
        for (auto& c: cur) res.push_back(c->val);

        return res;
    }

    void build_graph(Graph& g, TreeNode* node, TreeNode* parent) {
        if (node->left) {
            g[node].push_back(node->left);
            build_graph(g, node->left, node);
        }
        if (node->right) {
            g[node].push_back(node->right);
            build_graph(g, node->right, node);
        }
        if (parent) {
            g[node].push_back(parent);
        }
    }

};
