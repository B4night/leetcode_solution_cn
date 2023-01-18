#include "header.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
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
            path.push_back(nums[i]);
            used[i] = 1;
            traverse(path, nums, used);
            used[i] = 0;
            path.pop_back();
        }
    }
};