#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* initTree(vector<int> v) {     // 根据v的元素建树,建树规则和leetcode相同,用于调试代码
    int len = v.size();
    vector<TreeNode*> nodes(len, nullptr);
    for (int i = len - 1; i >= 0; i--) {
        nodes[i] = new TreeNode(v[i]);
        if (2 * i + 1 < len) {
            nodes[i]->left = nodes[(i << 1) + 1];
        }
        if (2 * i + 2 < len) {
            nodes[i]->right = nodes[(i << 1) + 2];
        }
    }
    return nodes[0];
}