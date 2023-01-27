#include "header.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        traverse(0, 0, board);
    }
    bool traverse(int row, int col, vector<vector<char>>& board) {  // 填第(row, col)个格子
    // 由于寻找一种解,所以返回值是bool
        if (row == 8 && col == 9) {     // 此时说明全填完了
            return true;
        }
        if (col == 9) {     // 此时到了边界,开始下一行
            row++;
            col = 0;
        }
        if (board[row][col] != '.') {   // 数字是固定的,跳过不填
            return traverse(row, col + 1, board);
        }
        // (row, col)是'.',需要填数字上去
        for (int i = 1; i <= 9; i++) {
            if (!valid(row, col, i + '0', board)) {     // 判断填i + '0'是否有效
                continue;
            }
            board[row][col] = i + '0';
            if (traverse(row, col + 1, board)) {    // 如果找到了一个解,就返回
                return true;
            }
            board[row][col] = '.';      // 回溯
        }
        return false;
    }
    bool valid(int row, int col, int val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {   // exam row
            if (i == col) {
                continue;
            }
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {   // exam col
            if (i == row) {
                continue;
            }
            if (board[i][col] == val) {
                return false;
            }
        }
        int startX = row / 3;
        int startY = col / 3;
        startX *= 3;
        startY *= 3;
        for (int i = startX; i < startX + 3; i++) {     // 检验3*3的块
            for (int j = startY; j < startY + 3; j++) {
                if (i == row && j == col) {
                    continue;
                }
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> v = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution().solveSudoku(v);
    cout << 123;
}
