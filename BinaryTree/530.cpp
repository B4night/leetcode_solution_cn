#include "header.h"

class Solution {
public:
    vector<int> v;
    int getMinimumDifference(TreeNode* root) {
        // 根据中序遍历得到递增的序列
        // 找到最小差值
        traverse(root);
        int ans = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            ans = min(ans, v[i + 1] - v[i]);
        }
        return ans;
    }
    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
};