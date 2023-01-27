#include "header.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 此题与T236类似,都是求最近公共祖先,但是本树为BST,遇到第一个值在[minVal,maxVal]区间的结点就可以确定是最近公共祖先
        auto iter = root;
        int minVal = min(p->val, q->val);       
        int maxVal = max(p->val, q->val);

        while (iter->val < minVal || iter->val > maxVal) {
            if (iter->val < minVal) {
                iter = iter->right;
            } else {
                iter = iter->left;
            }
        }
        return iter;
    }
};