#include "header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        using T = ListNode*;
        T p = head;
        T pre = nullptr;
        T new_head = head->next;
        
        p->next = new_head->next;
        new_head->next = p;
        
        while (true) {
            pre = p;
            p = p->next;
            if (!p) break;
            T tmp = p->next;
            if (!tmp) break;
            p->next = tmp->next;
            tmp->next = p;
            pre->next = tmp;
        }
        
        return new_head;
    }
};

int main() {
    using T = ListNode;
    T n1(3);
    T n2(2, &n1);
    T n3(1, &n2);
    Solution().swapPairs(&n3);
}