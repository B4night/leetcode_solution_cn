#include "header.h"

class Solution {
    int is_palidrome[20][20];   // is_palidrome[i][j] = 1当s[i, j)为回文串
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        computePalidrome(s);    // 先预处理 is_palidrome
        traverse(vector<string>(), 0, s);   // 回溯
        return ans;
    }
    void computePalidrome(string& s) {
        memset(is_palidrome, 0, sizeof(is_palidrome));
        int len = s.size();
        for (int i = 0; i < len; i++) {
            is_palidrome[i][i + 1] = 1;
        }
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j <= len; j++) {
                if (j == i + 1) {   // 此时就一个字符s[i]
                    is_palidrome[i][j] = 1;
                } else if (j == i + 2) {    // 此时就两个字符s[i], s[i + 1]
                    is_palidrome[i][j] = (s[i] == s[j - 1] ? 1 : 0);
                } else {    // 此时多个字符s[i, j)
                    is_palidrome[i][j] = (s[i] == s[j - 1] ? 1 : 0) & is_palidrome[i + 1][j - 1];
                }
            }
        }
    }
    void traverse(vector<string> path, int curIdx, string& s) {
        if (curIdx == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = curIdx + 1; i <= s.size(); i++) {
            if (is_palidrome[curIdx][i] == 0) {
                continue;
            }
            path.push_back(s.substr(curIdx, i - curIdx));
            traverse(path, i, s);
            path.pop_back();
        }
    }
};

int main() {
    Solution().partition("aab");
}