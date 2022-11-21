# leetcode_solution
leetcode题解

Readme中会介绍比较tricky的做法.

## reverse

### [翻转字符串中单词](https://leetcode.cn/problems/reverse-words-in-a-string/)

题目要颠倒单词的顺序, 常规做法将每个单词加入到`stack`中, 然后逆序构造一个字符串返回. 时间复杂度和空间复杂度都是O(n)

可以使用另一种思路来解决问题, 例`str = "   the   sky is blue"`

1. 解决前导空格和尾随空格和单词之间的多个空格, `str = "the sky is blue"`
2. 翻转字符串, `str = "eulb si yks eht"`
3. 每个单词反转, `str = "blue is sky the"`

此时空间复杂度变为O(1)

### [左旋转字符串](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

简单的做法是用两个字符串表示`str`的前一部分和后一部分, 再相加即可. 时间复杂度和空间复杂度都是O(n)

可以使用翻转来降低空间复杂度, 例`str = "abcdefgh", n = 3`

1. 翻转前n位, `str = "cbadefgh"`
2. 翻转后`str.size() - n`位, `str = "cbahgfed"`
3. 翻转str, `str = "defghabc"`

此时空间复杂度降为O(1)

## 队列

### [滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum)

思路: 使用优先队列, 元素为值和坐标组成的`pair`, 在将最大值存储到`vector<int> ans`中时需要先检验最大值的坐标是否合法

``` cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 使用优先队列
        priority_queue<pair<int, int>> pq;  //pair的第一个元素存值, 第二个元素存坐标
        vector<int> ans;
        int idx = 0;
        for (; idx < k; idx++) {
            pq.push({nums[idx], idx});
        } 
        ans.push_back(pq.top().first);	// 先处理nums[0, k)

        for (; idx < nums.size(); idx++) {	// 处理nums[k, len)
            pq.push({nums[idx], idx});
            while (pq.top().second < idx - k + 1) {	// 从优先队列中去掉不合法的最大值
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
```

