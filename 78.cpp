#include "header.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        traverse(vector<int>(), 0, nums); 
        return ans;
    }
    void traverse(vector<int> path, int idx, vector<int>& nums) {
        ans.push_back(path);      // 求幂集,所有的节点都需要记录,而不是只有叶子节点
        if (idx == nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            traverse(path, i + 1, nums);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> v = {1};
    Solution().subsets(v);
}