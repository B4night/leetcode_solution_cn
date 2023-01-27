#include "header.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        traverse(vector<int>(), 0, nums);
        return ans;
    }
    void traverse(vector<int> path, int idx, vector<int>& nums) {
        if (path.size() >= 2) {
            ans.push_back(path);
        }
        if (idx == nums.size()) {
            return;
        }

        // 这个traverse就是二叉树中的一个节点,path是当前节点的状态
        // 在下列循环中衍生出当前节点的所有有效的子节点,所以下列循环中的子节点都是处在同一层的
        
        // 使用set来避免同一层中选了相同的值
        // 如果当前path{1, 4}, 还剩下{7, 6, 7}没有选
        // 则子节点可以衍生出{1, 4, 7}, {1, 4, 6}, {1, 4, 7}这三个子节点
        // 很明显第二个{1, 4, 7}是重复的,所以使用set来避免这种情况发生
        // 示例图片的地址 https://img-blog.csdnimg.cn/20201124200229824.png
        set<int> s;
        for (int i = idx; i < nums.size(); i++) {
            if (s.count(nums[i])) {    
                // s中有nums[i]说明前面已经有了状态为(path+nums[i])这个状态的子节点
                // 为了避免重复状态的产生需要跳过
                continue;
            }
            if (path.size() == 0 || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                s.insert(nums[i]);  // 此时衍生出了path + nums[i]这个状态的子节点,为了避免重复需要将nums[i]加入到set中
                traverse(path, i + 1, nums);
                path.pop_back();
            }
        }
    }
};