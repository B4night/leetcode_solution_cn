#include "header.h"

class Solution {
public:
    vector<int> v;
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        traverse(root);
        int max_fre = 1;
        for (int lo = 0; lo < v.size(); lo++) {
            int cnt = 1;
            int hi = lo + 1;
            while (hi < v.size() && v[hi] == v[lo]) {
                cnt++;
                hi++;
            }
            if (cnt == max_fre) {
                ans.push_back(v[lo]);
            } else if (cnt > max_fre) {
                max_fre = cnt;
                ans.clear();
                ans.push_back(v[lo]);
            }
            lo = hi - 1;
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

int main() {
    using T = TreeNode;
    T t1(1);
    T t2(0);
    T t3(1);
    T t4(0);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    Solution().findMode(&t1);
}