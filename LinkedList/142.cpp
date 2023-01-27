#include "header.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        using T = ListNode*;

        // 解法1:使用map判重
        // map<T, int> m;
        // int idx = 0;
        // T p = head;
        // while (true) {
        //     if (p == nullptr)
        //         break;
        //     if (m.count(p) != 0)
        //         break;
        //     m[p] = idx;
        //     p = p->next;
        //     idx++;
        // }
        // return p;

        // 解法2:双指针法
        // 题解:https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#_142-%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8ii
        T fast = head;
        T slow = head;
        do {
            for (int i = 0; i < 2; i++) {
                if (fast == nullptr)
                    return nullptr;
                fast = fast->next;
            }
            slow = slow->next;
        } while (fast != slow);
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {
    using T = ListNode;
    T t1(-4);
    T t2(0, &t1);
    T t3(2, &t2);
    T t4(3, &t3);
    t1.next = &t2;
    Solution().detectCycle(&t4);
}