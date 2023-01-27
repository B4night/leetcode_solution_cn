#include "header.h"

class Solution {
public:
    // 在以root为根节点的树中寻找p, q的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) {
            return root;
        }
        auto leftPtr = lowestCommonAncestor(root->left, p, q);
        auto rightPtr = lowestCommonAncestor(root->right, p, q);
        if (leftPtr && rightPtr) { // 此时说明左子树和右子树中有p和q
            return root;
        } else if (leftPtr && !rightPtr) { // 此时说明只有左子树中有p, q
            return leftPtr;
        } else if (!leftPtr && rightPtr) { // 此时说明只有右子树有p, q
            return rightPtr;
        } else {
            return nullptr;
        }
        return nullptr;
    }
};