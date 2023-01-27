#include "header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)  // 当只有一个元素
            return nullptr;
        using T = ListNode*;
        T p = head;
        T next_n_p = p;
        for (int i = 0; i < n; i++)
            next_n_p = next_n_p->next;
        if (!next_n_p)  // 特殊判断,要删掉的结点刚好为head
            return head->next;
        
        T pre = nullptr;
        while (next_n_p) {  // p和next_n_p之间距离为n, 当next_n_p为nullptr时,p刚好为倒数第n个元素
            pre = p;
            p = p->next;
            next_n_p = next_n_p->next;
        }
        pre->next = p->next;
        return head;
    }
};