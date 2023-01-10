#include "header.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        traverse(vector<int>(), 1, 0, n, k);
        return ans;
    }
    void traverse(vector<int> path, int cur, int sum, int target, int limit) {
        if (sum == target && path.size() == limit) {
            ans.push_back(path);
            return;
        }
        if (path.size() > limit) {
            return;
        }
        if (sum > target) {
            return;
        }
        if (cur > 9) {
            return;
        }
        traverse(path, cur + 1, sum, target, limit);
        path.push_back(cur);
        traverse(path, cur + 1, sum + cur, target, limit);
    }
};