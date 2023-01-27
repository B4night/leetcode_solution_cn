#include "header.h"

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        traverse(vector<int>(), candidates, target, 0, 0);
        return vector<vector<int>>(s.begin(), s.end());
    }
    void traverse(vector<int> path, vector<int>& candidates, int target, int cur, int idx) {
        if (cur == target) {
            sort(path.begin(), path.end());
            s.insert(path);
            return;
        }
        if (cur > target) {
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            cur += candidates[i];
            path.push_back(candidates[i]);
            traverse(path, candidates, target, cur, idx);
            cur -= candidates[i];
            path.pop_back();
        }
    }
};