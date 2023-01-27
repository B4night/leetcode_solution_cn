#include "header.h"

class Solution {
    TreeNode* deleteNode(TreeNode* root, int key) { // 删除以root为根节点的BST树中值为key的结点,要求结果还是一颗BST
        if (!root) {
            return nullptr;
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left && root->right) {
                auto ret = root->right;
                delete root;
                return ret;
            } else if (root->left && !root->right) {
                auto ret = root->left;
                delete root;
                return ret;
            } else {
                auto successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }
                successor->left = root->left;
                auto tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        root->left = deleteNode(root->left, key);   // 递归处理左子树
        root->right = deleteNode(root->right, key); // 递归处理右子树
        return root;
    }
};
