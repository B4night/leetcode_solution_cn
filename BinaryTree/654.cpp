#include "header.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = nullptr;
        int max = -1;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }
        if (max == -1) {
            return root;
        }
        root = new TreeNode(max);
        vector<int> left(nums.begin(), nums.begin() + idx);
        root->left = constructMaximumBinaryTree(left);
        vector<int> right(nums.begin() + idx + 1, nums.end());
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};

int main() {
    vector<int> v = {3,2,1,6,0,5};
    Solution().constructMaximumBinaryTree(v);
}