#include "header.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while (p) {
            pre = p;
            if (p->val > val) {
                p = p->left;
            } else if (p->val < val) {
                p = p->right;
            } else {
                return root;
            }
        }
        if (val < pre->val) {
            pre->left = new TreeNode(val);
        } else {
            pre->right = new TreeNode(val);
        }
        return root;
    }
};