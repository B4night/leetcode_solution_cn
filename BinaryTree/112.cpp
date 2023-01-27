#include "header.h"

class Solution {
public:
    bool ans;
    int targetSum;
    bool hasPathSum(TreeNode* root, int targetSum) {
        ans = false;
        Solution::targetSum = targetSum;
        traverse(root, 0);
        return ans; 
    }
    void traverse(TreeNode* p, int curSum) {
        if (ans) {
            return;
        }
        if (!p) {
            return;
        }
        curSum += p->val;
        if (curSum == targetSum && !p->left && !p->right) { // p为路径上最后一个结点
            ans = true;
        }
        traverse(p->left, curSum);
        traverse(p->right, curSum);
    }
};