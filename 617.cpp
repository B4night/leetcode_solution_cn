#include "header.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* p = nullptr;
        dfs(p, root1, root2);
        return p;
    }
    void dfs(TreeNode*& p, TreeNode* r1, TreeNode* r2) {
        if (r1 && r2) {
            p = new TreeNode(r1->val + r2->val);
            dfs(p->left, r1->left, r2->left);
            dfs(p->right, r1->right, r2->right);
        } else if (r1 && !r2) {
            p = new TreeNode(r1->val);
            dfs(p->left, r1->left, nullptr);
            dfs(p->right, r1->right, nullptr);
        } else if (!r1 && r2) {
            p = new TreeNode(r2->val);
            dfs(p->left, nullptr, r2->left);
            dfs(p->right, nullptr, r2->right);
        }
    }
};