#include "header.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        traverse(string(), root, ans);
        return ans;
    }
    void traverse(string path, TreeNode* p, vector<string>& ans) {
        if (!p) {
            return;
        }
        if (!p->left && !p->right) {
            path += to_string(p->val);
            ans.push_back(path);
            return;
        }
        path += to_string(p->val) + "->";
        traverse(path, p->left, ans);
        traverse(path, p->right, ans);
    }
};