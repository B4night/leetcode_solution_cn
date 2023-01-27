#include "header.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); i++)
        //     nums[i] *= nums[i];
        // sort(nums.begin(), nums.end());
        // return nums;

        // 使用双指针法
        int lo = 0;
        int hi = nums.size() - 1;
        vector<int> res(nums.size(), -1);
        int idx = res.size() - 1;
        while (lo <= hi) {
            if (abs(nums[lo]) >= abs(nums[hi])) {
                res[idx] = nums[lo] * nums[lo];
                idx--;
                lo++;
            } else {
                res[idx] = nums[hi] * nums[hi];
                idx--;
                hi--;
            }
        }
        return res;
    }
};

int main() {

}