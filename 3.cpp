#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {    // 滑动窗口
        if (s.size() == 0)
            return 0;
        set<char> se;
        int len = s.size();
        int i = 0;
        int j = 0;
        int ans = -1;
        while (j < len) {
            if (se.count(s[j]) == 0) {
                se.insert(s[j]);
                j++;
            } else {
                while (se.count(s[j]) != 0)
                    se.erase(s[i++]);
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};

int main() {
    Solution().lengthOfLongestSubstring("pwwwkew");
}