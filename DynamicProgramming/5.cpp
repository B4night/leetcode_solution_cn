#include "header.h"

class Solution {
public:
    bool dp[1005][1005] = { 0 }; // dp[i][j] = 1说明s[i..j]为回文串,i<=j
    string longestPalindrome(string s) {
        int len = s.size();
        int lo = 0;
        int hi = 0;
        int cnt = 1;
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for (int i = len; i >= 0; i--) {    // 注意循环方向:自底向上
            for (int j = i + 1; j < len; j++) {
                if (s[i] != s[j])
                    dp[i][j] = false;   // s[i..j]不可能为回文串
                else {
                    if (j - i + 1 <= 3) // 此时s[i]=s[j], 如果长度为2,或3,则一定为回文串
                        dp[i][j] = true;
                    else {
                        dp[i][j] = dp[i + 1][j - 1];    // s[i]=s[j],若dp[i+1][j-1]为真,则dp[i][j]为真
                    }
                }

                if (dp[i][j] && j - i + 1 >= cnt) { // 更新边界
                        cnt = j - i + 1;
                        lo = i;
                        hi = j;
                }

            }
        }
        return string(s, lo, hi - lo + 1);
    }

    // 转置s,得到reverse_s,求两个字符串的最长公共子串. 错误, 如"aacadxacaa"的最长公共子串是"acaa"而不是"aca"
    // string longestPalindrome(string s) {
    //     if (s.size() == 0) return 0;
    //     string reverse_s;
    //     for (auto iter = s.rbegin(); iter != s.rend(); iter++)
    //         reverse_s.push_back(*iter);
    //     int dp[1005][1005] = {0};
    //     int len = s.size();
    //     int ans = 1;
    //     int idx = 0;
    //     for (int i = 0; i < len; i++) {
    //         if (s[i] == reverse_s[0])
    //             dp[i][0] = 1;
    //         if (reverse_s[i] == s[0])
    //             dp[0][i] = 1;
    //     }
    //     for (int i = 1; i < len; i++) {
    //         for (int j = 1; j < len; j++) {
    //             if (s[i] == reverse_s[j])
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             else
    //                 dp[i][j] = 0;
    //             if (ans <= dp[i][j]) {
    //                 ans = dp[i][j];
    //                 idx = i - ans + 1;
    //             }
    //         }
    //     }
    //     return string(s, idx, ans);
    // }
};

int main() {
    cout << Solution().longestPalindrome("cbbd");
}