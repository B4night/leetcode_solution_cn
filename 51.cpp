#include "header.h"

class Solution {
    int idx[10];    // 第i行皇后的纵坐标为idx[i]
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vs;
        traverse(vs, 0, n);
        return ans;
    }
    void traverse(vector<string>& path, int cur, int n) {
        if (cur == n) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {   // 判断第i行的第0列到第(n-1)列
            if (!valid(cur, i)) {   // 判断(cur, i)这个位置是否合法
                continue;
            }
            string tmpStr(n, '.');
            tmpStr[i] = 'Q';
            path.push_back(tmpStr);
            idx[cur] = i;
            traverse(path, cur + 1, n);
            path.pop_back();
        }
    }
    bool valid(int row, int col) {
        for (int i = 0; i <= row - 1; i++) {
            if (idx[i] == col) {
                return false;
            }
            if (row - i == col - idx[i]) {
                return false;
            }
            if (row - i == idx[i] - col) {
                return false;
            }
        }
        return true;
    }
};