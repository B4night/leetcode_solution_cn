#include "header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int idx = 0; idx < len - 2; idx++) {
            if (idx && nums[idx - 1] == nums[idx])  // 去重
                continue;

            int lo = idx + 1;   // 双指针法
            int hi = len - 1;
            while (lo < hi) {
                int sum = nums[idx] + nums[lo] + nums[hi];
                if (sum > 0)
                    hi--;
                else if (sum < 0)
                    lo++;
                else {
                    ans.push_back(std::move(vector<int>({nums[idx], nums[lo], nums[hi]})));
                    lo++;
                    hi--;
                    while (lo < hi && nums[lo] == nums[lo - 1]) lo++;   // 去掉相同的
                    while (lo < hi && nums[hi] == nums[hi + 1]) hi--;   // 去掉相同的
                }
            }
        }
        return ans;
    }
};