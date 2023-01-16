#include "header.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        traverse(vector<int>(), 0, nums, used);
        return ans;
    }
    void traverse(vector<int> path, int idx, vector<int>& nums, vector<int>& used) {
        ans.push_back(path);
        if (idx == nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {  // 和40.cpp采用的方法类似
                continue;
            }
            path.push_back(nums[i]);
            used[i] = 1;
            traverse(path, i + 1, nums, used);
            used[i] = 0;
            path.pop_back();
        }
    }
};

int main() {
    vector<int> v = {1, 2};
    Solution().subsetsWithDup(v);
}