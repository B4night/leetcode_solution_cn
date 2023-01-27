#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jw = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ans = new ListNode(-1);   // 哨兵
        ListNode* p3 = ans->next;
        ListNode* pre = ans;

        while (p1 && p2) {  // 处理l1和l2重叠的部分
            int tmp = p1->val + p2->val + jw;
            jw = tmp / 10;
            tmp %= 10;
            p3 = new ListNode(tmp);
            pre->next = p3;
            pre = p3;
            p3 = p3->next;

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1) {    // 如果l1的结点比l2多
            int tmp = p1->val + jw;
            jw = tmp / 10;
            tmp = tmp % 10;
            p3 = new ListNode(tmp);
            pre->next = p3;
            pre = p3;
            p3 = p3->next;

            p1 = p1->next;
        }

        while (p2) {
            int tmp = p2->val + jw;
            jw = tmp / 10;
            tmp = tmp % 10;
            p3 = new ListNode(tmp);
            pre->next = p3;
            pre = p3;
            p3 = p3->next;

            p2 = p2->next;
        }

        while (jw) {    // 最后处理进位
            p3 = new ListNode(jw % 10);
            pre->next = p3;
            pre = p3;
            p3 = p3->next;
            jw = jw / 10;
        }

        return ans->next;
    }
};

int main() {
    ListNode t1(3);
    ListNode t2(4, &t1);
    ListNode t3(2, &t2);

    ListNode t4(4);
    ListNode t5(6, &t4);
    ListNode t6(5, &t5);

    Solution().addTwoNumbers(&t3, &t6);
}