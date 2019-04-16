#include <sstream>
#include <stack>
#include <stdio.h>
using namespace std;
struct TreeNode {
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val_) : val(val_) {}
};

TreeNode *recoverFromPreorder(string S) {
    const int len = static_cast<int>(S.size());

    stack<TreeNode *> path;
    int depth = -1;
    int i = 0;
    while (i < len) {
        // 计算深度
        int j = 0;
        while (i < len && S[i] == '-') {
            j++;
            i++;
        }
        // 计算数值
        int val = 0;
        while (i < len && S[i] != '-') {
            val = val * 10 + (S[i] - '0');
            i++;
        }
        printf("depth : %d, val : %d\n", depth, val);

        TreeNode *node = new TreeNode(val);
        if (path.empty()) {
            path.push(node);
            printf("push %d\n", node->val);
        } else {
            if (j > depth) {
                path.top()->left = node;
                path.push(node);
                printf("push %d\n", node->val);
            } else {
                while (j <= depth--) {
                    printf("pop %d\n", path.top()->val);
                    path.pop();
                }
                path.top()->right = node;
                path.push(node);
                printf("push %d\n", node->val);
            }
        }
        depth = j;
    }

    TreeNode *root = nullptr;
    while (!path.empty()) {
        root = path.top();
        path.pop();
    }
    return root;
}
int main(int argc, const char *argv[]) {
    string s = "1-401--349---90--88";
    TreeNode *root = recoverFromPreorder(s);
}
