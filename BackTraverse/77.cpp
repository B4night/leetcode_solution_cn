#include "header.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        traverse(ans, vector<int>(), 1, n, k);
        return ans;
    }
    void traverse(vector<vector<int>>& ans, vector<int> path, int cur, int limit, int num) {
        if (path.size() == num) {
            ans.push_back(path);
            return;
        }
        if (cur > limit) {
            return;
        }
        if (limit - cur + 1 + path.size() < num) {
            return;
        }
        traverse(ans, path, cur + 1, limit, num);
        path.push_back(cur);
        traverse(ans, path, cur + 1, limit, num);
    }
};