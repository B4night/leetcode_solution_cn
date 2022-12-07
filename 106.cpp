#include "header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        if (inorder.empty()) {
            return root;
        }
        int root_val = postorder[postorder.size() - 1];
        int idx = 0;
        for (; idx < inorder.size(); idx++) {
            if (inorder[idx] == root_val) {
                break;
            }
        }
        root = new TreeNode(root_val);
        vector<int> left_in(inorder.begin(), inorder.begin() + idx);
        vector<int> left_po(postorder.begin(), postorder.begin() + idx);
        root->left = buildTree(left_in, left_po);
        vector<int> right_in(inorder.begin() + idx + 1, inorder.end());
        vector<int> right_po(postorder.begin() + idx, postorder.end() - 1);
        root->right = buildTree(right_in, right_po);
        return root;
    }
};