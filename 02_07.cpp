#include "header.h"
// https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        using T = ListNode*;

        // 用set来判断是否有重复的结点
        // set<T> s;
        // T p = headA;
        // while (p != nullptr) {
        //     s.insert(p);
        //     p = p->next;
        // }
        // p = headB;
        // while (p != nullptr) {
        //     if (s.count(p)) return p;
        //     p = p->next;
        // }
        // return nullptr;

        // 方法2:若headA和headB有交点,则说明headA和headB的后半部分是一样的
        T p1 = headA;
        T p2 = headB;
        int cnt1 = 0;
        int cnt2 = 0;
        while (p1) {
            cnt1++;
            p1 = p1->next;
        }
        while (p2) {
            cnt2++;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if (cnt1 > cnt2) {
            for (int i = 0; i < cnt1 - cnt2; i++)
                p1 = p1->next;
        } else {
            for (int i = 0; i < cnt2 - cnt1; i++)
                p2 = p2->next;
        }
        while (p1 && p2) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};

int main() {

}