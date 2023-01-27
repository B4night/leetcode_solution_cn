#include "header.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 使用优先队列
        priority_queue<pair<int, int>> pq;  //pair的第一个元素存值, 第二个元素存坐标
        vector<int> ans;
        int idx = 0;
        for (; idx < k; idx++) {
            pq.push({nums[idx], idx});
        } 
        ans.push_back(pq.top().first);

        for (; idx < nums.size(); idx++) {
            pq.push({nums[idx], idx});
            while (pq.top().second < idx - k + 1) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// TLE
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         queue<int> q;
//         vector<int> ans;
//         int max_num = 1 << 31;

//         int idx = 0;
//         for (; idx < k; idx++) {
//             q.push(nums[idx]);
//             max_num = max(max_num, nums[idx]);
//         }
//         ans.push_back(max_num);

//         for (; idx < nums.size(); idx++) {
//             if (nums[idx] >= max_num) {
//                 max_num = nums[idx];
//                 q.pop();
//                 q.push(nums[idx]);
//             } else {
//                 int tmp = q.front();
//                 if (tmp < max_num) {
//                     q.push(nums[idx]);
//                     q.pop();
//                 } else {
//                     q.pop();
//                     q.push(nums[idx]);
//                     queue<int> q_tmp = q;
//                     max_num = 1 << 31;
//                     while (q_tmp.size()) {
//                         max_num = max(max_num, q_tmp.front());
//                         q_tmp.pop();
//                     }
//                 }
//             }
//             ans.push_back(max_num);
//         }
//         return ans;
//     }
// };

int main() {
    vector<int> v = {7, 2, 4};
    Solution().maxSlidingWindow(v, 2);
}