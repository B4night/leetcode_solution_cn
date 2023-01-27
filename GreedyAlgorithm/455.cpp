#include "header.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx_g = 0;
        int idx_s = 0;
        int cnt = 0;
        while (idx_g < g.size() && idx_s < s.size()) {
            if (g[idx_g] <= s[idx_s]) {
                idx_g++;
                idx_s++;
                cnt++;
            } else {
                idx_s++;
            }
        }
        return cnt;
    }
};