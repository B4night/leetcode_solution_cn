#include "header.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < len; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int lo = j + 1;
                int hi = len - 1;
                while (lo < hi) {
                    long long sum = nums[i] + nums[j];  // 由于范围的问题,需要分来开相加,否则4个10 0000 0000相加,会超出int的范围
                    sum += nums[lo] + nums[hi];
                    if (sum > target)
                        hi--;
                    else if (sum < target)
                        lo++;
                    else {
                        ans.push_back(std::move(vector<int>({nums[i], nums[j], nums[lo], nums[hi]})));
                        lo++;
                        hi--;
                        while (lo < hi && nums[lo] == nums[lo - 1]) lo++;   // 去掉相同的
                        while (lo < hi && nums[hi] == nums[hi + 1]) hi--;   // 去掉相同的
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v = {1,0,-1,0,-2,2};
    Solution().fourSum(v, 0);
}
// -2 -1 0 0 1 2 