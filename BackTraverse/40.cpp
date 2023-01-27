#include "header.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 先排序
        vector<int> used(candidates.size(), 0);     // 定义used数组,剪枝用
        traverse(0, 0, target, candidates, vector<int>(), used);
        return ans;
    }
    void traverse(int cur, int cur_sum, int target, vector<int>& candidates, vector<int> path, vector<int>& used) {
        if (cur_sum > target) {     // 剪枝1
            return;
        }
        if (cur_sum == target) {    // 剪枝2
            ans.push_back(path);
            return;
        }
        for (int i = cur; i < candidates.size() && candidates[i] + cur_sum <= target; i++) {    // 剪枝3
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0) {  // 剪枝4
                /* 
                简单介绍一下为什么当candidates[i]和candidates[i - 1]相等且used[i - 1] = 0的时候剪枝
                若used[i - 1]等于0,且此时轮到了第i个元素,则在回溯的过程中candidates[i - 1]已经被选过traverse了然后才轮到的candidates[i]
        
                假设candidates[i + 1, ...]为集合B, candidates[i] = candidates[i - 1] = val
                那么组成target的格式有: (B_1, B_2为B的子集)
                1. val + B_1    选candidates[i - 1]
                2. 2*val + B_2  选candidates[i - 1]和candidates[i]

                此时轮到了candidates[i], 如果选candidates[i], 则会有val + B_1这个组合方式, 会产生重复.
                因此跳过candidates[i]
                */
                continue;
            }
            used[i] = 1;
            path.push_back(candidates[i]);
            traverse(i + 1, cur_sum + candidates[i], target, candidates, path, used);
            used[i] = 0;
            path.pop_back();
        }
    }
};

int main() {
    vector<int> v = {10,1,2,7,6,1,5};
    Solution().combinationSum2(v, 8);
}