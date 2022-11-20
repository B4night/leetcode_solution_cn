#include "header.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = 0;
        int hi = 0;
        int cnt = (1 << 30);

        sort(nums.begin(), nums.end());
        int cur = 0;
        while (hi < nums.size()) {
            cur += nums[hi];
            hi++;
            if (cur >= target) {
                while (lo < hi) {
                    if (cur - nums[lo] >= target) {
                        cur -= nums[lo];
                        lo++;
                    } else
                        break;
                }
                cnt = min(cnt, hi - lo);
            }
        }
        return cnt == (1 << 30) ? 0 : cnt;
    }
};

int main() {
    vector<int> v({12,28,83,4,25,26,25,2,25,25,25,12});
    Solution().minSubArrayLen(213, v);
}