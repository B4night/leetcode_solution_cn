#include "header.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int cnt = 0;
        if (root->left && !root->left->left && !root->left->right) {
            cnt = root->left->val;
        }
        return cnt + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};