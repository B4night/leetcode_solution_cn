#include "header.h"

class Solution {
public:
    map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return ans;
        }
        traverse("", digits, 0, digits.size());
        return ans;
    }
    void traverse(string path, string& digits, int idx, int limit) {
        if (idx == limit) {
            ans.push_back(path);
            return;
        }
        
        for (auto& elem : m[digits[idx]]) {
            path += elem;
            traverse(path, digits, idx + 1, limit);
            path.pop_back();
        }
    }
};