#include "header.h"

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> m1;   // m1中存储nums1和nums2元素所有可能的和
        map<int, int> m2;   // m1中存储nums1和nums2元素所有可能的和
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) 
            for (int j = 0; j < nums2.size(); j++)
                m1[nums1[i]+nums2[j]]++;
        
        for (int i = 0; i < nums3.size(); i++) 
            for (int j = 0; j < nums4.size(); j++)
                m2[nums3[i]+nums4[j]]++;
        
        for (const auto& [key, value] : m1) {
            if (m2.count(-key))
                ans += value * m2[-key];    // 如果m1中值为key的组合有value个,m2中值为-key的组合有m2[-key]个
                // 则m1和m2中值为0的组合有value * m2[-key]个
        }
        return ans;
    }
};

int main() {

}