#include "header.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = 0;
        int right = 0;
        auto *p = root->left;
        while (p) {
            left++;
            p = p->left;
        }
        p = root->right;
        while (p) {
            right++;
            p = p->right;
        }
        if (left == right) {    // 如果以root为根节点的树为完全满二叉树,那么left和right的值相等
            return (1 << left) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
    cout << 123;
}