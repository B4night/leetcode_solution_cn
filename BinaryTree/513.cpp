#include "header.h"

class Solution {
public:
    int max_depth = -1;
    int ans = 0;
    int findBottomLeftValue(TreeNode* root) {
        // 最底层最左边,即深度最大时前序遍历第一个碰到的结点值
        traverse(root, 0);
        return ans;
    }
    void traverse(TreeNode* p, int current_depth) {
        if (!p) {
            return;
        }
        if (current_depth > max_depth) {
            max_depth = current_depth;
            ans = p->val;
        }
        traverse(p->left, current_depth + 1);
        traverse(p->right, current_depth + 1);
    }
};