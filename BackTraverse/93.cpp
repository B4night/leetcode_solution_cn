#include "header.h"

class Solution {
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        traverse(vector<int>(), 0, s);
        return ans;
    }
    void traverse(vector<int> path, int curIdx, string& s) {
        if (curIdx == s.size()) {
            if (path.size() == 4) {
                string tmpS;
                for (int i = 0; i < 3; i++) {
                    tmpS += to_string(path[i]) + '.';
                }
                tmpS += to_string(path[3]);
                ans.push_back(tmpS);
            } 
            return;
        }
        for (int i = curIdx + 1; i <= s.size(); i++) {
            int tmpVal = atoi(s.substr(curIdx, i - curIdx).c_str());
            if (tmpVal > 255) {
                break;
            }
            if (s[curIdx] == '0' && i != curIdx + 1) {  // 避免"023"这种情况
                break;
            }
            path.push_back(tmpVal);
            traverse(path, i, s);
            path.pop_back();
        }
    }
};