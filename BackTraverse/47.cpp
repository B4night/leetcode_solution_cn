#include "header.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());     // 这种有重复元素且要求答案中去重的都需要对nums进行排序后再处理
        traverse(vector<int>(), nums, used);
        return ans;
    }
    void traverse(vector<int> path, vector<int>& nums, vector<int>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = 1;
            traverse(path, nums, used);
            path.pop_back();
            used[i] = 0;
        }
    }
};