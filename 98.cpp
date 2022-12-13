#include "header.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {   // 验证BST合法:中序遍历为一个升序结点
        vector<int> v;
        traverse(v, root);
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1] >= v[i]) {
                return false;
            }
        }
        return true;
    }
    void traverse(vector<int>& v, TreeNode* root) {
        if (!root) {
            return;
        }
        traverse(v, root->left);
        v.push_back(root->val);
        traverse(v, root->right);
    }
};