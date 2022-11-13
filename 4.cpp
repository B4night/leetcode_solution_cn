#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // merge 2 array. O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        ans.reserve(len);
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        if (i == nums1.size())
            while (j < nums2.size())
                ans.push_back(nums2[j++]);
        else 
            while (i < nums1.size())
                ans.push_back(nums1[i++]);
        if (len % 2)
            return ans[len / 2];
        return (ans[len/2 - 1] + ans[len/2]) / 2.0;
    }
};

int main() {
    vector<int> v1{1, 3};
    vector<int> v2{2};
    Solution().findMedianSortedArrays(v1, v2);
}